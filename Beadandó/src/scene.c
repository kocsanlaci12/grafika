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

    return distance < threshold; // Ha a távolság kisebb, mint egy küszöb, akkor ütközés van
}

void init_scene(Scene* scene)
{
    load_model(&(scene->ground), "assets/models/ground.obj");
    scene->ground_texture_id = load_texture("assets/textures/fu5.jpg");
    load_model(&(scene->cube), "assets/models/asd.obj");
    scene->texture_id = load_texture("assets/textures/bokor.jpg");
    load_model(&(scene->jak), "assets/models/cube.obj");
    scene->jak_texture_id = load_texture("assets/textures/cube.png");
    load_model(&(scene->goal), "assets/models/goal.obj");
    scene->jak_texture_id = load_texture("assets/textures/cube.png");
    load_model(&(scene->villain), "assets/models/villain.obj");
    scene->jak_texture_id = load_texture("assets/textures/cube.png");
    load_model(&(scene->villain2), "assets/models/villain2.obj");
    scene->jak_texture_id = load_texture("assets/textures/cube.png");
    load_model(&(scene->villain3), "assets/models/villain3.obj");
    scene->jak_texture_id = load_texture("assets/textures/cube.png");
    load_model(&(scene->villain4), "assets/models/villain4.obj");
    scene->jak_texture_id = load_texture("assets/textures/cube.png");
    load_model(&(scene->villain5), "assets/models/villain5.obj");
    scene->jak_texture_id = load_texture("assets/textures/cube.png");

    float threshold = 1.0f;
    
    do {
        scene->jak_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
        scene->jak_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    } while (is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain_pos_x, scene->villain_pos_y, threshold) || 
             is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain2_pos_x, scene->villain2_pos_y, threshold) ||
             is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain3_pos_x, scene->villain3_pos_y, threshold) ||
             is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain4_pos_x, scene->villain4_pos_y, threshold) ||
             is_overlap(scene->jak_pos_x, scene->jak_pos_y, scene->villain5_pos_x, scene->villain5_pos_y, threshold));

    scene->goal_pos_x = 0.0f; // Tehát a (0,0) koordinátán lesz
    scene->goal_pos_y = 0.0f;
    
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

    do {
        scene->villain5_pos_x = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
        scene->villain5_pos_y = ((float)rand() / RAND_MAX) * 8.0f - 4.0f;
    } while (is_overlap(scene->villain5_pos_x, scene->villain5_pos_y, scene->jak_pos_x, scene->jak_pos_y, threshold) ||
                is_overlap(scene->villain5_pos_x, scene->villain5_pos_y, scene->villain2_pos_x, scene->villain2_pos_y, threshold) ||
                is_overlap(scene->villain5_pos_x, scene->villain5_pos_y, scene->villain3_pos_x, scene->villain3_pos_y, threshold) ||
                is_overlap(scene->villain5_pos_x, scene->villain5_pos_y, scene->villain4_pos_x, scene->villain4_pos_y, threshold) ||
                is_overlap(scene->villain5_pos_x, scene->villain5_pos_y, scene->villain_pos_x, scene->villain_pos_y, threshold));


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


    scene->jak_collected = false;

    scene->score = 0;

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    glBindTexture(GL_TEXTURE_2D, scene->jak_texture_id);

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 0.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;
    
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
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

bool is_jak_in_reach(const Camera* camera, const Scene* scene)
{
    float dx = scene->jak_pos_x - camera->position.x;
    float dy = scene->jak_pos_y - camera->position.y;
    float distance = sqrt(dx * dx + dy * dy);

    return distance < 1.0f;  // 1 egységen belül "fel lehet venni"
}


void update_scene(Scene* scene)
{
    typedef struct {
        float* pos_x;
        float* pos_y;
        float* target_x;
        float* target_y;
        bool is_active;
    } VillainData;

    VillainData villains[5] = {
        { &scene->villain_pos_x, &scene->villain_pos_y, &scene->villain_target1_x, &scene->villain_target1_y, true },
        { &scene->villain2_pos_x, &scene->villain2_pos_y, &scene->villain_target2_x, &scene->villain_target2_y, scene->score >= 2 },
        { &scene->villain3_pos_x, &scene->villain3_pos_y, &scene->villain_target3_x, &scene->villain_target3_y, scene->score >= 3 },
        { &scene->villain4_pos_x, &scene->villain4_pos_y, &scene->villain_target4_x, &scene->villain_target4_y, scene->score >= 4 },
        { &scene->villain5_pos_x, &scene->villain5_pos_y, &scene->villain_target5_x, &scene->villain_target5_y, scene->score >= 5 },
    };

    if (!scene->jak_collected) {
        for (int i = 0; i < 5; i++) {
            if (!villains[i].is_active) {
                continue;
            }

            float* pos_x = villains[i].pos_x;
            float* pos_y = villains[i].pos_y;

            // Villain1 kör mozgásának beállítása
            if (i == 0) {
                static int villain1_target_index = 0; // Statikus változó, hogy nyomon követhessük az indexet
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

            // Villain5 kör mozgásának beállítása
            else if (i == 4) {
                static int villain5_target_index = 0;
                float target_points[4][2] = {
                    {3.5f, 3.5f},
                    {-3.5f, 3.5f},
                    {-3.5f, -3.5f},
                    {3.5f, -3.5f}
                };

                *villains[i].target_x = target_points[villain5_target_index][0];
                *villains[i].target_y = target_points[villain5_target_index][1];

                float dx = *villains[i].target_x - *pos_x;
                float dy = *villains[i].target_y - *pos_y;
                float distance = sqrtf(dx * dx + dy * dy);

                if (distance < 0.1f) {
                    villain5_target_index = (villain5_target_index + 1) % 4;
                }

                float dir_x = dx / distance;
                float dir_y = dy / distance;

                *pos_x += dir_x * VILLAIN_SPEED;
                *pos_y += dir_y * VILLAIN_SPEED;
            }

            // A koordináták korlátozása, hogy -4.0 és 4.0 között maradjanak
            if (*pos_x < -4.0f) *pos_x = -4.0f;
            if (*pos_x > 4.0f) *pos_x = 4.0f;
            if (*pos_y < -4.0f) *pos_y = -4.0f;
            if (*pos_y > 4.0f) *pos_y = 4.0f;
        }
        return; // Kilépünk, hogy a szabad mozgás ne induljon el
    }
    // Küszöbérték a közelben lévő gonoszok távolságának ellenőrzésére
    float threshold = 0.8f;
    float jak_threshold = 1.3f; // A Jak és a gonosz közötti minimális távolság

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

        if (distance_jak < jak_threshold) {
            // Ha túl közel van Jakhoz, váltsunk irányt
            *target_x = *pos_x + (rand() % 2 == 0 ? 1 : -1) * (rand() % 2 == 0 ? 1 : -1);
            *target_y = *pos_y + (rand() % 2 == 0 ? 1 : -1) * (rand() % 2 == 0 ? 1 : -1);
        }
    }
}



void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    draw_origin();

    
    if (!scene->jak_collected) {
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->jak_texture_id);
        glTranslatef(scene->jak_pos_x, scene->jak_pos_y, 0.6f);
        draw_model(&(scene->jak));
        glPopMatrix();
    }

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->ground_texture_id);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    draw_model(&(scene->ground));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->jak_texture_id);
    glTranslatef(scene->villain_pos_x, scene->villain_pos_y, 0.4f); // A kockát a föld közepére helyezzük
    draw_model(&(scene->villain)); 
    glPopMatrix();

    if (scene->score >= 2) {
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->jak_texture_id);
        glTranslatef(scene->villain2_pos_x, scene->villain2_pos_y, 0.4f);
        draw_model(&(scene->villain2));
        glPopMatrix();
    }
    if (scene->score >= 3) {
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->jak_texture_id);
        glTranslatef(scene->villain3_pos_x, scene->villain3_pos_y, 0.4f);
        draw_model(&(scene->villain3));
        glPopMatrix();
    }
    if (scene->score >= 4) {
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->jak_texture_id);
        glTranslatef(scene->villain4_pos_x, scene->villain4_pos_y, 0.4f);
        draw_model(&(scene->villain4));
        glPopMatrix();
    }
    if (scene->score >= 5) {
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->jak_texture_id);
        glTranslatef(scene->villain5_pos_x, scene->villain5_pos_y, 0.4f);
        draw_model(&(scene->villain5));
        glPopMatrix();
    }

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    glTranslatef(0.0f, 0.0f, 0.0f); // A kockát a föld közepére helyezzük
    draw_model(&(scene->cube)); // Itt rajzoljuk a kockát
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->jak_texture_id);
    glTranslatef(0.0f, 0.0f, 0.0f); // A kockát a föld közepére helyezzük
    draw_model(&(scene->goal)); // Itt rajzoljuk a kockát
    glPopMatrix();

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
