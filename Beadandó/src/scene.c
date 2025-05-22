#include "scene.h"
#include <stdlib.h>  
#include <time.h>
#include <math.h>

#include <obj/load.h>
#include <obj/draw.h>
#define VILLAIN_SPEED 0.001f


bool is_overlap(float x1, float y1, float x2, float y2, float threshold)
{
    float dx = x1 - x2;
    float dy = y1 - y2;
    float distance = sqrt(dx * dx + dy * dy);

    return distance < threshold; 
}

void init_scene(Scene* scene)
{
    scene->skybox_texture[0] = load_texture("assets/textures/felso1.png");
    scene->skybox_texture[1] = load_texture("assets/textures/felso1.png");
    scene->skybox_texture[2] = load_texture("assets/textures/felso1.png");
    scene->skybox_texture[3] = load_texture("assets/textures/felso1.png");
    scene->skybox_texture[4] = load_texture("assets/textures/felso1.png");
    scene->skybox_texture[5] = load_texture("assets/textures/felso1.png");
    load_model(&(scene->ground), "assets/models/ground.obj");
    scene->ground_texture_id = load_texture("assets/textures/fu6.jpg");
    load_model(&(scene->cube), "assets/models/asd.obj");
    scene->texture_id = load_texture("assets/textures/bokor.jpg");
    load_model(&(scene->jak), "assets/models/chicken.obj");
    scene->jak_texture_id = load_texture("assets/textures/wolf.png");
    load_model(&(scene->goal), "assets/models/goal.obj");
    scene->goal_texture_id = load_texture("assets/textures/cube.png");
    load_model(&(scene->villain), "assets/models/fridge.obj");
    scene->fridge_texture_id = load_texture("assets/textures/fridge.png");
    load_model(&(scene->villain2), "assets/models/snowman.obj");
    scene->snowman_texture_id = load_texture("assets/textures/snowman.png");
    load_model(&(scene->villain3), "assets/models/demon.obj");
    scene->demon_texture_id = load_texture("assets/textures/demon2.png");
    load_model(&(scene->villain4), "assets/models/fogmonster.obj");
    scene->fogmonster_texture_id = load_texture("assets/textures/fogmonster.png");
    
    
    char filename[64];
    for (int i = 0; i <= 9; i++) {
        sprintf(filename, "assets/textures/%d.png", i);
        scene->score_digit_textures[i] = load_texture(filename);
    }

    float threshold = 1.0f;
    
     do {
        scene->jak_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
        scene->jak_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    } while (is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain_pos_x, scene->villain_pos_y, threshold) || 
             is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain2_pos_x, scene->villain2_pos_y, threshold) ||
             is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain3_pos_x, scene->villain3_pos_y, threshold) ||
             is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain4_pos_x, scene->villain4_pos_y, threshold) ||
             is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain5_pos_x, scene->villain5_pos_y, threshold));

    do {
        scene->villain_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
        scene->villain_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    } while (is_overlap(scene->villain_pos_x, scene->villain_pos_y, scene->jak_pos_x, scene->jak_pos_y, threshold) ||
             is_overlap(scene->villain_pos_x, scene->villain_pos_y, scene->villain2_pos_x, scene->villain2_pos_y, threshold) ||
             is_overlap(scene->villain_pos_x, scene->villain_pos_y, scene->villain3_pos_x, scene->villain3_pos_y, threshold) ||
             is_overlap(scene->villain_pos_x, scene->villain_pos_y, scene->villain4_pos_x, scene->villain4_pos_y, threshold) ||
             is_overlap(scene->villain_pos_x, scene->villain_pos_y, scene->villain5_pos_x, scene->villain5_pos_y, threshold));

    do {
        scene->villain2_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
        scene->villain2_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    } while (is_overlap(scene->villain2_pos_x, scene->villain2_pos_y, scene->jak_pos_x, scene->jak_pos_y, threshold) ||
             is_overlap(scene->villain2_pos_x, scene->villain2_pos_y, scene->villain_pos_x, scene->villain_pos_y, threshold) ||
             is_overlap(scene->villain2_pos_x, scene->villain2_pos_y, scene->villain3_pos_x, scene->villain3_pos_y, threshold) ||
             is_overlap(scene->villain2_pos_x, scene->villain2_pos_y, scene->villain4_pos_x, scene->villain4_pos_y, threshold) ||
             is_overlap(scene->villain2_pos_x, scene->villain2_pos_y, scene->villain5_pos_x, scene->villain5_pos_y, threshold));

    do {
        scene->villain3_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
        scene->villain3_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    } while (is_overlap(scene->villain3_pos_x, scene->villain3_pos_y, scene->jak_pos_x, scene->jak_pos_y, threshold) ||
             is_overlap(scene->villain3_pos_x, scene->villain3_pos_y, scene->villain2_pos_x, scene->villain2_pos_y, threshold) ||
             is_overlap(scene->villain3_pos_x, scene->villain3_pos_y, scene->villain_pos_x, scene->villain_pos_y, threshold) ||
             is_overlap(scene->villain3_pos_x, scene->villain3_pos_y, scene->villain4_pos_x, scene->villain4_pos_y, threshold) ||
             is_overlap(scene->villain3_pos_x, scene->villain3_pos_y, scene->villain5_pos_x, scene->villain5_pos_y, threshold));

    do {
        scene->villain4_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
        scene->villain4_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    } while (is_overlap(scene->villain4_pos_x, scene->villain4_pos_y, scene->jak_pos_x, scene->jak_pos_y, threshold) ||
                is_overlap(scene->villain4_pos_x, scene->villain4_pos_y, scene->villain2_pos_x, scene->villain2_pos_y, threshold) ||
                is_overlap(scene->villain4_pos_x, scene->villain4_pos_y, scene->villain3_pos_x, scene->villain3_pos_y, threshold) ||
                is_overlap(scene->villain4_pos_x, scene->villain4_pos_y, scene->villain_pos_x, scene->villain_pos_y, threshold) ||
                is_overlap(scene->villain4_pos_x, scene->villain4_pos_y, scene->villain5_pos_x, scene->villain5_pos_y, threshold));


    scene->villain_target1_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    scene->villain_target1_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    scene->villain_target2_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    scene->villain_target2_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    scene->villain_target3_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    scene->villain_target3_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    scene->villain_target4_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    scene->villain_target4_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    scene->villain_target5_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    scene->villain_target5_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;

    scene->goal_pos_x = 0.0f;
    scene->goal_pos_y = 0.0f;

    scene->jak_collected = false;
    scene->gameover = false;
    scene->win = false;

    scene->score = 0;
    scene->villain_state = 0;
    scene->villain_state2 = 0;
    scene->villain_state3 = 0;

    scene->light_intensity = 2.0f;

    init_rain(&scene->rain);
    init_snow(&scene->rain);
        
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 10.0;
    
}

void render_score(Scene* scene)
{
    int score = scene->score;

    int window_width = 1024;  
    int window_height = 768;

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, window_width, 0, window_height);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    // Score méretei
    int digit_width = 100;
    int digit_height = 100;

    int start_x = window_width - digit_width - 10; 
    int y = window_height - digit_height - 10;     


    if (score == 0) {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        return;
    }

    // Számjegyeket jobbról balra rajzoljuk
    // Először kiszámoljuk, hány számjegy van
    int digits[10];
    int num_digits = 0;
    while (score > 0) {
        digits[num_digits++] = score % 10;
        score /= 10;
    }

    // Kirajzolás jobbról balra
    for (int i = 0; i < num_digits; i++) {
        int digit = digits[i]; 
        GLuint tex = scene->score_digit_textures[digit];
        glBindTexture(GL_TEXTURE_2D, tex);

        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);

        glBegin(GL_QUADS);
            glTexCoord2f(0,1); glVertex2i(start_x - i*digit_width, y);
            glTexCoord2f(1,1); glVertex2i(start_x - i*digit_width + digit_width, y);
            glTexCoord2f(1,0); glVertex2i(start_x - i*digit_width + digit_width, y + digit_height);
            glTexCoord2f(0,0); glVertex2i(start_x - i*digit_width, y + digit_height);
        glEnd();

        glDisable(GL_TEXTURE_2D);
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void set_lighting(const Scene* scene)
{
    float intensity = scene->light_intensity;
    GLfloat ambient_light[] = { 0.7f * intensity, 0.7f * intensity, 0.7f * intensity, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);

    GLfloat diffuse_light[] = { 1.0f * intensity, 1.0f * intensity, 1.0f * intensity, 1.0f };
    GLfloat specular_light[] = { 1.0f * intensity, 1.0f * intensity, 1.0f * intensity, 1.0f };

    GLfloat light_position[] = { 0.0f, 0.0f, 5.0f, 1.0f };  

    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void push_out_of_villain(Camera* camera, float villain_x, float villain_y, float push_distance)
{
    float dx = camera->position.x - villain_x;
    float dy = camera->position.y - villain_y;

    float dist = sqrt(dx * dx + dy * dy);

    if (dist < push_distance && dist > 0.0f) {  
        float push_dx = dx / dist * (push_distance - dist);
        float push_dy = dy / dist * (push_distance - dist);

        camera->position.x += push_dx;
        camera->position.y += push_dy;
    }
}

void check_villain_collision_and_push(Camera* camera, Scene* scene)
{
    float push_distance = 0.5f;  

    push_out_of_villain(camera, scene->villain_pos_x, scene->villain_pos_y, push_distance);
    if (scene->score >= 2){
    push_out_of_villain(camera, scene->villain2_pos_x, scene->villain2_pos_y, push_distance);}
    if (scene->score >= 3){
    push_out_of_villain(camera, scene->villain3_pos_x, scene->villain3_pos_y, push_distance);}
    if (scene->score >= 4){
    push_out_of_villain(camera, scene->villain4_pos_x, scene->villain4_pos_y, push_distance);}
}

void check_jak_collision_and_push(Camera* camera, Scene* scene)
{
    if (scene->jak_collected) {
        // Ha megfogtad a Jakot, ne legyen ütközés
        return;
    }
    float push_distance = 0.4f;  // vagy amekkora az ütközési küszöböd

    push_out_of_villain(camera, scene->jak_pos_x, scene->jak_pos_y, push_distance);
}

void clamp_camera_position_to_walls(Camera* camera)
{
    if (camera->position.x < -4.3f) camera->position.x = -4.3f;
    if (camera->position.x > 4.3f) camera->position.x = 4.3f;

    if (camera->position.y < -3.8f) camera->position.y = -3.8f;
    if (camera->position.y > 4.8f) camera->position.y = 4.8f;
}

bool is_jak_in_reach(const Camera* camera, const Scene* scene)
{
    float dx = scene->jak_pos_x - camera->position.x;
    float dy = scene->jak_pos_y - camera->position.y;
    float distance = sqrt(dx * dx + dy * dy);

    return distance < 0.5f;  // 1 egységen belül "fel lehet venni"
}


void update_scene(Scene* scene, Camera* camera)
{
    update_rain(&scene->rain);
    update_snow(&scene->rain);
    typedef struct {
        float* pos_x;
        float* pos_y;
        float* target_x;
        float* target_y;
        bool is_active;
    } VillainData;

    VillainData villains[4] = {
        { &scene->villain_pos_x, &scene->villain_pos_y, &scene->villain_target1_x, &scene->villain_target1_y, true },
        { &scene->villain2_pos_x, &scene->villain2_pos_y, &scene->villain_target2_x, &scene->villain_target2_y, scene->score >= 2 },
        { &scene->villain3_pos_x, &scene->villain3_pos_y, &scene->villain_target3_x, &scene->villain_target3_y, scene->score >= 3 },
        { &scene->villain4_pos_x, &scene->villain4_pos_y, &scene->villain_target4_x, &scene->villain_target4_y, scene->score >= 4 },
    };

    if (!scene->jak_collected) {
        for (int i = 0; i < 4; i++) {
            if (!villains[i].is_active) {
                continue;
            }

            float* pos_x = villains[i].pos_x;
            float* pos_y = villains[i].pos_y;

            // Villain1 kör mozgásának beállítása
            if (i == 0) {
                static int villain1_target_index = 0; 
                // A négy célpont
                float target_points[4][2] = {
                    {-1.0f, 0.0f},
                    {1.0f, 0.0f},
                    {0.0f, 1.0f},
                    {0.0f, -1.0f}
                };

                // Beállítjuk a célpontot
                *villains[i].target_x = target_points[villain1_target_index][0];
                *villains[i].target_y = target_points[villain1_target_index][1];

                // Ha elérte a célpontot, akkor lépjünk a következő célpontra
                float dx = *villains[i].target_x - *pos_x;
                float dy = *villains[i].target_y - *pos_y;
                float distance = sqrtf(dx * dx + dy * dy);

                if (distance < 0.1f) {
                    // Ciklus léptetése, ha elérte a célpontot
                    villain1_target_index = (villain1_target_index + 1) % 4; // 0-3 közötti értékre léptetjük
                }

                // Mozgás a cél felé, azaz a szabad mozgás sebességét alkalmazzuk
                float dir_x = dx / distance;
                float dir_y = dy / distance;

                *pos_x += dir_x * VILLAIN_SPEED;
                *pos_y += dir_y * VILLAIN_SPEED;
            }

            // Villain2 kör mozgásának beállítása
            else if (i == 1) {
                static int villain2_target_index = 0;
                float target_points[4][2] = {
                    {2.0f, 2.0f},
                    {-2.0f, 2.0f},
                    {-2.0f, -2.0f},
                    {2.0f, -2.0f}
                };

                *villains[i].target_x = target_points[villain2_target_index][0];
                *villains[i].target_y = target_points[villain2_target_index][1];

                float dx = *villains[i].target_x - *pos_x;
                float dy = *villains[i].target_y - *pos_y;
                float distance = sqrtf(dx * dx + dy * dy);

                if (distance < 0.1f) {
                    villain2_target_index = (villain2_target_index + 1) % 4;
                }

                float dir_x = dx / distance;
                float dir_y = dy / distance;

                *pos_x += dir_x * VILLAIN_SPEED;
                *pos_y += dir_y * VILLAIN_SPEED;
            }

            // Villain3 kör mozgásának beállítása
            else if (i == 2) {
                static int villain3_target_index = 0;
                float target_points[4][2] = {
                    {2.5f, 2.5f},
                    {-2.5f, 2.5f},
                    {-2.5f, -2.5f},
                    {2.5f, -2.5f}
                };

                *villains[i].target_x = target_points[villain3_target_index][0];
                *villains[i].target_y = target_points[villain3_target_index][1];

                float dx = *villains[i].target_x - *pos_x;
                float dy = *villains[i].target_y - *pos_y;
                float distance = sqrtf(dx * dx + dy * dy);

                if (distance < 0.1f) {
                    villain3_target_index = (villain3_target_index + 1) % 4;
                }

                float dir_x = dx / distance;
                float dir_y = dy / distance;

                *pos_x += dir_x * VILLAIN_SPEED;
                *pos_y += dir_y * VILLAIN_SPEED;
            }

            // Villain4 kör mozgásának beállítása
            else if (i == 3) {
                static int villain4_target_index = 0;
                float target_points[4][2] = {
                    {3.0f, 3.0f},
                    {-3.0f, 3.0f},
                    {-3.0f, -3.0f},
                    {3.0f, -3.0f}
                };

                *villains[i].target_x = target_points[villain4_target_index][0];
                *villains[i].target_y = target_points[villain4_target_index][1];

                float dx = *villains[i].target_x - *pos_x;
                float dy = *villains[i].target_y - *pos_y;
                float distance = sqrtf(dx * dx + dy * dy);

                if (distance < 0.1f) {
                    villain4_target_index = (villain4_target_index + 1) % 4;
                }

                float dir_x = dx / distance;
                float dir_y = dy / distance;

                *pos_x += dir_x * VILLAIN_SPEED;
                *pos_y += dir_y * VILLAIN_SPEED;
            }

            if (*pos_x < -4.3f) *pos_x = -4.3f;
            if (*pos_x > 4.3f) *pos_x = 4.3f;
            if (*pos_y < -3.8f) *pos_y = -3.8f;
            if (*pos_y > 4.8f) *pos_y = 4.8f;
        }
        return; 
    }

    float threshold = 0.8f;
    float jak_threshold = 1.3f; 
    float gameover_threshold = 0.5f; // A Jak és a gonosz közötti minimális távolság

    for (int i = 0; i < 5; i++) {
        if (!villains[i].is_active) {
            continue;
        }

        float* pos_x = villains[i].pos_x;
        float* pos_y = villains[i].pos_y;
        float* target_x = villains[i].target_x;
        float* target_y = villains[i].target_y;

        // Gonosztevő mozgása
        float dx = *target_x - *pos_x;
        float dy = *target_y - *pos_y;
        float distance = sqrtf(dx * dx + dy * dy);

        // Ha a célpont elég közel van, új célpontot választunk
        if (distance < 0.1f) {
            float new_target_x, new_target_y, new_distance;
            do {
                new_target_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                new_target_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
                float ddx = new_target_x - *pos_x;
                float ddy = new_target_y - *pos_y;
                new_distance = sqrtf(ddx * ddx + ddy * ddy);
            } while (new_distance < 1.5f);  // biztosítjuk, hogy a cél elég messze legyen

            *target_x = new_target_x;
            *target_y = new_target_y;
        } else {
            float dir_x = dx / distance;
            float dir_y = dy / distance;

            *pos_x += dir_x * VILLAIN_SPEED;
            *pos_y += dir_y * VILLAIN_SPEED;
        }

        // Ellenőrizzük, hogy a gonosztevők ne ütközzenek egymásba
        for (int j = 0; j < 5; j++) {
            if (i == j || !villains[j].is_active) {
                continue;
            }

            float* other_pos_x = villains[j].pos_x;
            float* other_pos_y = villains[j].pos_y;

            float dx = *pos_x - *other_pos_x;
            float dy = *pos_y - *other_pos_y;
            float distance = sqrtf(dx * dx + dy * dy);

            // Ha a két gonosztevő túl közel van egymáshoz, új irányt választunk
            if (distance < threshold) {
                // Változtassunk irányt, hogy elkerüljék az ütközést
                *target_x = *pos_x + (rand() % 2 == 0 ? 1 : -1) * (rand() % 2 == 0 ? 1 : -1);
                *target_y = *pos_y + (rand() % 2 == 0 ? 1 : -1) * (rand() % 2 == 0 ? 1 : -1);
            }
        }

        // Ellenőrizzük, hogy a gonosz ne ütközzön Jak-kal
        float dx_jak = *pos_x - scene->jak_pos_x;
        float dy_jak = *pos_y - scene->jak_pos_y;
        float distance_jak = sqrtf(dx_jak * dx_jak + dy_jak * dy_jak);

        float dx_cam = *pos_x - camera->position.x;
        float dy_cam = *pos_y - camera->position.y;
        float distance_cam = sqrtf(dx_cam * dx_cam + dy_cam * dy_cam);

        if (distance_cam < gameover_threshold) {
            scene->gameover = true;
            break;  // elég egyszer megtalálni, kiléphetünk
        }

        if (distance_jak < jak_threshold) {
            // Ha túl közel van Jakhoz, váltsunk irányt
            *target_x = *pos_x + (rand() % 2 == 0 ? 1 : -1) * (rand() % 2 == 0 ? 1 : -1);
            *target_y = *pos_y + (rand() % 2 == 0 ? 1 : -1) * (rand() % 2 == 0 ? 1 : -1);
        }
    }
}

void draw_skybox(const Scene* scene)
{
    float size = 6.0f;  
    float skybox_x = 0.0f;
    float skybox_y = 0.0f;
    float skybox_z = 0.0f;

    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

    glTranslatef(skybox_x, skybox_y, skybox_z);

    // RIGHT
    glBindTexture(GL_TEXTURE_2D, scene->skybox_texture[0]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( size, -size, -size);
        glTexCoord2f(1, 0); glVertex3f( size, -size,  size);
        glTexCoord2f(1, 1); glVertex3f( size,  size,  size);
        glTexCoord2f(0, 1); glVertex3f( size,  size, -size);
    glEnd();

    // LEFT
    glBindTexture(GL_TEXTURE_2D, scene->skybox_texture[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
        glTexCoord2f(1, 0); glVertex3f(-size, -size, -size);
        glTexCoord2f(1, 1); glVertex3f(-size,  size, -size);
        glTexCoord2f(0, 1); glVertex3f(-size,  size,  size);
    glEnd();

    // TOP
    glBindTexture(GL_TEXTURE_2D, scene->skybox_texture[2]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-size,  size, -size);
        glTexCoord2f(1, 0); glVertex3f( size,  size, -size);
        glTexCoord2f(1, 1); glVertex3f( size,  size,  size);
        glTexCoord2f(0, 1); glVertex3f(-size,  size,  size);
    glEnd();

    // BOTTOM
    glBindTexture(GL_TEXTURE_2D, scene->skybox_texture[3]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
        glTexCoord2f(1, 0); glVertex3f( size, -size,  size);
        glTexCoord2f(1, 1); glVertex3f( size, -size, -size);
        glTexCoord2f(0, 1); glVertex3f(-size, -size, -size);
    glEnd();

    // FRONT
    glBindTexture(GL_TEXTURE_2D, scene->skybox_texture[4]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( size, -size,  size);
        glTexCoord2f(1, 0); glVertex3f(-size, -size,  size);
        glTexCoord2f(1, 1); glVertex3f(-size,  size,  size);
        glTexCoord2f(0, 1); glVertex3f( size,  size,  size);
    glEnd();

    // BACK
    glBindTexture(GL_TEXTURE_2D, scene->skybox_texture[5]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
        glTexCoord2f(1, 0); glVertex3f( size, -size, -size);
        glTexCoord2f(1, 1); glVertex3f( size,  size, -size);
        glTexCoord2f(0, 1); glVertex3f(-size,  size, -size);
    glEnd();

    glPopMatrix();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}


void render_scene(Scene* scene)
{
    draw_skybox(scene);
    set_material(&(scene->material));
    set_lighting(scene);

    if (scene->score >= 2 && scene->villain_state < 1) {
    load_model(&(scene->villain), "assets/models/snowman.obj");
    scene->fridge_texture_id = load_texture("assets/textures/snowman.png");
    scene->villain_state = 1;
}
    if (scene->score >= 3 && scene->villain_state < 2) {
        load_model(&(scene->villain), "assets/models/demon2.obj");
        scene->fridge_texture_id = load_texture("assets/textures/demon2.png");
        load_model(&(scene->villain2), "assets/models/demon3.obj");
        scene->snowman_texture_id = load_texture("assets/textures/demon2.png");
        scene->villain_state = 2;
    }
    if (scene->score >= 4 && scene->villain_state < 3) {
        load_model(&(scene->villain), "assets/models/fogmonster.obj");
        scene->fridge_texture_id = load_texture("assets/textures/fogmonster.png");
        load_model(&(scene->villain2), "assets/models/fogmonster2.obj");
        scene->snowman_texture_id = load_texture("assets/textures/fogmonster.png");
        load_model(&(scene->villain3), "assets/models/fogmonster3.obj");
        scene->demon_texture_id = load_texture("assets/textures/fogmonster.png");
        scene->villain_state = 3;
    }
    
    if (!scene->jak_collected) {
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->jak_texture_id);
        glTranslatef(scene->jak_pos_x, scene->jak_pos_y, 0.4f);
        draw_model(&(scene->jak));
        glPopMatrix();
    }

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->ground_texture_id);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    draw_model(&(scene->ground));
    glPopMatrix();

    glPushMatrix();
    if (scene->villain_state == 0) {
        glBindTexture(GL_TEXTURE_2D, scene->fridge_texture_id);
    } else if(scene->villain_state == 1) {
        glBindTexture(GL_TEXTURE_2D, scene->snowman_texture_id);
    }
    else if(scene->villain_state == 2) {
        glBindTexture(GL_TEXTURE_2D, scene->demon_texture_id);
    }
    else {
        glBindTexture(GL_TEXTURE_2D, scene->fogmonster_texture_id);
    }
    glTranslatef(scene->villain_pos_x, scene->villain_pos_y, 0.4f); 
    draw_model(&(scene->villain)); 
    glPopMatrix();

    if (scene->score >= 2) {
        if (scene->score < 3){
            render_snow(&scene->rain);}
        glPushMatrix();
        if (scene->villain_state == 1) {
            glBindTexture(GL_TEXTURE_2D, scene->snowman_texture_id);
        } else if(scene->villain_state == 2) {
            glBindTexture(GL_TEXTURE_2D, scene->demon_texture_id);
        }
        else {
            glBindTexture(GL_TEXTURE_2D, scene->fogmonster_texture_id);
        }
        glTranslatef(scene->villain2_pos_x, scene->villain2_pos_y, 0.4f);
        draw_model(&(scene->villain2));
        glPopMatrix();
    }
    if (scene->score >= 3) {
        if (scene->score < 4){
            render_rain(&scene->rain);}
        glPushMatrix();
        if (scene->villain_state == 2) {
            glBindTexture(GL_TEXTURE_2D, scene->demon_texture_id);
        } 
        else {
            glBindTexture(GL_TEXTURE_2D, scene->fogmonster_texture_id);
        }
        glTranslatef(scene->villain3_pos_x, scene->villain3_pos_y, 0.4f);
        draw_model(&(scene->villain3));
        glPopMatrix();
    }
    if (scene->score >= 5) {
        glDisable(GL_FOG);
    } else if (scene->score >= 4) {
        glEnable(GL_FOG);

        GLfloat fogColor[4] = { 0.7f, 0.7f, 0.7f, 1.0f };
        glFogfv(GL_FOG_COLOR, fogColor);

        glFogi(GL_FOG_MODE, GL_EXP2);
        glFogf(GL_FOG_DENSITY, 0.4f);
    }

    if (scene->score >= 4) {
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->fogmonster_texture_id);
        glTranslatef(scene->villain4_pos_x, scene->villain4_pos_y, 0.4f);
        draw_model(&(scene->villain4));
        glPopMatrix();
    }
    if (scene->score == 5){
    scene->win = true;}

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    glTranslatef(0.0f, 0.0f, 0.0f); 
    draw_model(&(scene->cube)); 
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->goal_texture_id);
    glTranslatef(0.1f, 0.7f, 0.6f); 
    glPopMatrix();
    render_score(scene);

}

float random_in_range(float min, float max)
{
    return min + (float)rand() / ((float)RAND_MAX / (max - min));
}

void init_rain(RainSystem* rain)
{
    rain->count = MAX_RAINDROPS;
    for (int i = 0; i < rain->count; ++i) {
        rain->raindrops[i].x = random_in_range(-4.3, 4.3);
        rain->raindrops[i].y = random_in_range(-3.8, 4.8);       
        rain->raindrops[i].z = random_in_range(5, 15);       
        rain->raindrops[i].speed = random_in_range(0.05f, 0.2f);
    }
}

void update_rain(RainSystem* rain)
{
    for (int i = 0; i < rain->count; ++i) {
        rain->raindrops[i].z -= rain->raindrops[i].speed;  
        if (rain->raindrops[i].z < 0) {
            rain->raindrops[i].z = random_in_range(5, 15); 
            rain->raindrops[i].x = random_in_range(-4.3, 4.3);
            rain->raindrops[i].y = random_in_range(-3.8, 4.8);  
        }
    }
}

void render_rain(const RainSystem* rain)
{
    glColor3f(0.2f, 0.2f, 1.0f); 

    glBegin(GL_LINES);
    for (int i = 0; i < rain->count; ++i) {
        float x = rain->raindrops[i].x;
        float y = rain->raindrops[i].y;
        float z = rain->raindrops[i].z;
        glVertex3f(x, y, z);
        glVertex3f(x, y, z + 0.2f);  
    }
    glEnd();
}

void init_snow(RainSystem* snow)
{
    snow->count = MAX_RAINDROPS;
    for (int i = 0; i < snow->count; ++i) {
        snow->raindrops[i].x = random_in_range(-4.3, 4.3);
        snow->raindrops[i].y = random_in_range(-3.8, 4.8);       
        snow->raindrops[i].z = random_in_range(5, 15);       
        snow->raindrops[i].speed = random_in_range(0.005f, 0.03f); 
    }
}

void update_snow(RainSystem* snow)
{
    for (int i = 0; i < snow->count; ++i) {
        snow->raindrops[i].z -= snow->raindrops[i].speed;
        if (snow->raindrops[i].z < 0) {
            snow->raindrops[i].z = random_in_range(5, 15);
            snow->raindrops[i].x = random_in_range(-4.3, 4.3);
            snow->raindrops[i].y = random_in_range(-3.8, 4.8);
        }
    }
}

void render_snow(const RainSystem* snow)
{
    glDisable(GL_LIGHTING);              
    glColor3f(1.0f, 1.0f, 1.0f);          
    glPointSize(4.0f);                 

    glBegin(GL_POINTS);
    for (int i = 0; i < snow->count; ++i) {
        float x = snow->raindrops[i].x;
        float y = snow->raindrops[i].y;
        float z = snow->raindrops[i].z;
        glVertex3f(x, y, z);
    }
    glEnd();

    glEnable(GL_LIGHTING);               
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
