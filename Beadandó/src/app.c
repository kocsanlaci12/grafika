#include "app.h"

#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>  
#include <time.h>



void init_app(App* app, int width, int height)
{
    int error_code;
    int inited_loaders;

    app->is_running = false;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
        return;
    }

    app->window = SDL_CreateWindow(
        "Cube!",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_OPENGL);
    if (app->window == NULL) {
        printf("[ERROR] Unable to create the application window!\n");
        return;
    }

    inited_loaders = IMG_Init(IMG_INIT_PNG);
    if (inited_loaders == 0) {
        printf("[ERROR] IMG initialization error: %s\n", IMG_GetError());
        return;
    }

    app->gl_context = SDL_GL_CreateContext(app->window);
    if (app->gl_context == NULL) {
        printf("[ERROR] Unable to create the OpenGL context!\n");
        return;
    }

    init_opengl();
    reshape(width, height);

    init_camera(&(app->camera));
    init_scene(&(app->scene));

    app->is_running = true;
}

void init_opengl()
{
    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(0.1, 0.1, 0.1, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearDepth(1.0);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(
        -.08, .08,
        -.06, .06,
        .1, 10
    );
}

void handle_app_events(App* app)
{
    SDL_Event event;
    static bool is_mouse_down = false;
    static int mouse_x = 0;
    static int mouse_y = 0;
    int x;
    int y;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                app->is_running = false;
                break;
            case SDL_SCANCODE_W:
                set_camera_speed(&(app->camera), 1);
                break;
            case SDL_SCANCODE_S:
                set_camera_speed(&(app->camera), -1);
                break;
            case SDL_SCANCODE_A:
                set_camera_side_speed(&(app->camera), 1);
                break;
            case SDL_SCANCODE_D:
                set_camera_side_speed(&(app->camera), -1);
                break;
            
            case SDL_SCANCODE_F:
                if (!app->scene.jak_collected && is_jak_in_reach(&(app->camera), &(app->scene))) {
                    app->scene.jak_collected = true;
                    printf("Felvetted a jak-ot!\n");
                }
                break;
            case SDL_SCANCODE_G:
                if (app->scene.jak_collected) {
                    // Eldobás: kamera előtt 1.5 egységgel
                    float angle = degree_to_radian(app->camera.rotation.z);
                    app->scene.jak_pos_x = app->camera.position.x + cos(angle) * 1.5f;
                    app->scene.jak_pos_y = app->camera.position.y + sin(angle) * 1.5f;
            
                    app->scene.jak_collected = false;
                    printf("Eldobtad a jak-ot!\n");

                    float jx = app->scene.jak_pos_x;
                    float jy = app->scene.jak_pos_y;
                    float gx = app->scene.goal_pos_x;
                    float gy = app->scene.goal_pos_y;

                    float half_size = 1.0f; // A goal.obj mérete

                    if (fabs(jx - gx) < half_size && fabs(jy - gy) < half_size) {
                        printf("Teleportalas...\n");
                        app->scene.score++;
                        printf("Jelenlegi pontszam: %d\n", app->scene.score);

                        float threshold = 1.0f; // Küszöbérték az ütközéshez

// Jak pozíciójának generálása
                        do {
                            app->scene.jak_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                            app->scene.jak_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                        } while (is_overlap(app->scene.jak_pos_x, app->scene.jak_pos_y, app->scene.villain_pos_x, app->scene.villain_pos_y, threshold) ||
                                is_overlap(app->scene.jak_pos_x, app->scene.jak_pos_y, app->scene.villain2_pos_x, app->scene.villain2_pos_y, threshold) ||
                                is_overlap(app->scene.jak_pos_x, app->scene.jak_pos_y, app->scene.villain3_pos_x, app->scene.villain3_pos_y, threshold) ||
                                is_overlap(app->scene.jak_pos_x, app->scene.jak_pos_y, app->scene.villain4_pos_x, app->scene.villain4_pos_y, threshold) ||
                                is_overlap(app->scene.jak_pos_x, app->scene.jak_pos_y, app->scene.villain5_pos_x, app->scene.villain5_pos_y, threshold));

// Villain pozíciók generálása
                        do {
                            app->scene.villain_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                            app->scene.villain_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                        } while (is_overlap(app->scene.villain_pos_x, app->scene.villain_pos_y, app->scene.jak_pos_x, app->scene.jak_pos_y, threshold) ||
                                is_overlap(app->scene.villain_pos_x, app->scene.villain_pos_y, app->scene.villain2_pos_x, app->scene.villain2_pos_y, threshold) ||
                                is_overlap(app->scene.villain_pos_x, app->scene.villain_pos_y, app->scene.villain3_pos_x, app->scene.villain3_pos_y, threshold) ||
                                is_overlap(app->scene.villain_pos_x, app->scene.villain_pos_y, app->scene.villain4_pos_x, app->scene.villain4_pos_y, threshold) ||
                                is_overlap(app->scene.villain_pos_x, app->scene.villain_pos_y, app->scene.villain5_pos_x, app->scene.villain5_pos_y, threshold));

// Villain2 pozíciók generálása
                        do {
                            app->scene.villain2_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                            app->scene.villain2_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                        } while (is_overlap(app->scene.villain2_pos_x, app->scene.villain2_pos_y, app->scene.jak_pos_x, app->scene.jak_pos_y, threshold) ||
                                is_overlap(app->scene.villain2_pos_x, app->scene.villain2_pos_y, app->scene.villain_pos_x, app->scene.villain_pos_y, threshold) ||
                                is_overlap(app->scene.villain2_pos_x, app->scene.villain2_pos_y, app->scene.villain3_pos_x, app->scene.villain3_pos_y, threshold) ||
                                is_overlap(app->scene.villain2_pos_x, app->scene.villain2_pos_y, app->scene.villain4_pos_x, app->scene.villain4_pos_y, threshold) ||
                                is_overlap(app->scene.villain2_pos_x, app->scene.villain2_pos_y, app->scene.villain5_pos_x, app->scene.villain5_pos_y, threshold));

                        do {
                            app->scene.villain3_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                            app->scene.villain3_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                        } while (is_overlap(app->scene.villain3_pos_x, app->scene.villain3_pos_y, app->scene.jak_pos_x, app->scene.jak_pos_y, threshold) ||
                                is_overlap(app->scene.villain3_pos_x, app->scene.villain3_pos_y, app->scene.villain2_pos_x, app->scene.villain2_pos_y, threshold) ||
                                is_overlap(app->scene.villain3_pos_x, app->scene.villain3_pos_y, app->scene.villain_pos_x, app->scene.villain_pos_y, threshold) ||
                                is_overlap(app->scene.villain3_pos_x, app->scene.villain3_pos_y, app->scene.villain4_pos_x, app->scene.villain4_pos_y, threshold) ||
                                is_overlap(app->scene.villain3_pos_x, app->scene.villain3_pos_y, app->scene.villain5_pos_x, app->scene.villain5_pos_y, threshold));
        
                        do {
                            app->scene.villain4_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                            app->scene.villain4_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                        } while (is_overlap(app->scene.villain4_pos_x, app->scene.villain4_pos_y, app->scene.jak_pos_x, app->scene.jak_pos_y, threshold) ||
                                is_overlap(app->scene.villain4_pos_x, app->scene.villain4_pos_y, app->scene.villain2_pos_x, app->scene.villain2_pos_y, threshold) ||
                                is_overlap(app->scene.villain4_pos_x, app->scene.villain4_pos_y, app->scene.villain3_pos_x, app->scene.villain3_pos_y, threshold) ||
                                is_overlap(app->scene.villain4_pos_x, app->scene.villain4_pos_y, app->scene.villain_pos_x, app->scene.villain_pos_y, threshold) ||
                                is_overlap(app->scene.villain4_pos_x, app->scene.villain4_pos_y, app->scene.villain5_pos_x, app->scene.villain5_pos_y, threshold));
        
                        do {
                            app->scene.villain5_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                            app->scene.villain5_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                        } while (is_overlap(app->scene.villain5_pos_x, app->scene.villain5_pos_y, app->scene.jak_pos_x, app->scene.jak_pos_y, threshold) ||
                                is_overlap(app->scene.villain5_pos_x, app->scene.villain5_pos_y, app->scene.villain2_pos_x, app->scene.villain2_pos_y, threshold) ||
                                is_overlap(app->scene.villain5_pos_x, app->scene.villain5_pos_y, app->scene.villain3_pos_x, app->scene.villain3_pos_y, threshold) ||
                                is_overlap(app->scene.villain5_pos_x, app->scene.villain5_pos_y, app->scene.villain4_pos_x, app->scene.villain4_pos_y, threshold) ||
                                is_overlap(app->scene.villain5_pos_x, app->scene.villain5_pos_y, app->scene.villain_pos_x, app->scene.villain_pos_y, threshold));
                        }
                }

                break;
                
            default:
                break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_S:
                set_camera_speed(&(app->camera), 0);
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_D:
                set_camera_side_speed(&(app->camera), 0);
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            is_mouse_down = true;
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x, &y);
            if (is_mouse_down) {
                rotate_camera(&(app->camera), mouse_x - x, mouse_y - y);
            }
            mouse_x = x;
            mouse_y = y;
            break;
        case SDL_MOUSEBUTTONUP:
            is_mouse_down = false;
            break;
        case SDL_QUIT:
            app->is_running = false;
            break;
        default:
            break;
        }
    }
}

void update_app(App* app)
{
    double current_time;
    double elapsed_time;

    current_time = (double)SDL_GetTicks() / 1000;
    elapsed_time = current_time - app->uptime;
    app->uptime = current_time;

    update_camera(&(app->camera), elapsed_time);
    update_scene(&(app->scene));
}

void render_app(App* app)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&(app->camera));
    render_scene(&(app->scene));
    glPopMatrix();

    if (app->camera.is_preview_visible) {
        show_texture_preview();
    }

    SDL_GL_SwapWindow(app->window);
}

void destroy_app(App* app)
{
    if (app->gl_context != NULL) {
        SDL_GL_DeleteContext(app->gl_context);
    }

    if (app->window != NULL) {
        SDL_DestroyWindow(app->window);
    }

    SDL_Quit();
}
