#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>



typedef struct Scene
{
    Model ground;
    Model cube;
    Model jak;
    Model goal;
    Model villain;
    Model villain2;
    Model villain3;
    Model villain4;
    Model villain5;
    Material material;
    GLuint texture_id;
    GLuint ground_texture_id;
    GLuint jak_texture_id;
    float jak_pos_x; // Jak pozíció x koordinátája
    float jak_pos_y;
    float goal_pos_x, goal_pos_y;
    float villain_pos_x;
    float villain_pos_y;
    float villain2_pos_x;
    float villain2_pos_y;
    float villain3_pos_x;
    float villain3_pos_y;
    float villain4_pos_x;
    float villain4_pos_y;
    float villain5_pos_x;
    float villain5_pos_y;
    bool jak_collected;
    int score;
    float villain_target1_x, villain_target1_y;
    float villain_target2_x, villain_target2_y;
    float villain_target3_x, villain_target3_y;
    float villain_target4_x, villain_target4_y;
    float villain_target5_x, villain_target5_y;
    bool jack_grabbed;



    
} Scene;

bool is_overlap(float x1, float y1, float x2, float y2, float threshold);
/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

bool is_jak_in_reach(const Camera* camera, const Scene* scene);
void grab_jack(void);
/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */