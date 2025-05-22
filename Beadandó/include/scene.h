#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>
#include <GL/glu.h>


#define MAX_RAINDROPS 500

typedef struct {
    float x, y, z;
    float speed;
} RainDrop;

typedef struct {
    RainDrop raindrops[MAX_RAINDROPS];
    int count;
} RainSystem;

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
    Material villain_material;
    GLuint texture_id;
    GLuint ground_texture_id;
    GLuint jak_texture_id;
    GLuint vill_texture_id;
    GLuint skybox_texture[6];
    GLuint score_digit_textures[10];
    GLuint fridge_texture_id;
    GLuint snowman_texture_id;
    GLuint demon_texture_id;
    GLuint fogmonster_texture_id;
    GLuint goal_texture_id;
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
    float villain_target1_x, villain_target1_y;
    float villain_target2_x, villain_target2_y;
    float villain_target3_x, villain_target3_y;
    float villain_target4_x, villain_target4_y;
    float villain_target5_x, villain_target5_y;
    float light_intensity;
    bool jak_collected;
    bool jack_grabbed;
    bool gameover;
    bool win;
    int score;
    int villain_state;
    int villain_state2;
    int villain_state3;
    RainSystem rain;   
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

void check_villain_collision_and_push(Camera* camera, Scene* scene);
void check_jak_collision_and_push(Camera* camera, Scene* scene);
void clamp_camera_position_to_walls(Camera* camera);

bool is_jak_in_reach(const Camera* camera, const Scene* scene);
void grab_jack(void);
/**
 * Update the scene.
 */
void set_villain_light(const Scene* scene);
void set_villain_material();
void update_scene(Scene* scene, Camera* camera);

/**
 * Render the scene objects.
 */
void render_scene(Scene* scene);
void init_rain(RainSystem* rain);
void update_rain(RainSystem* rain);
void render_rain(const RainSystem* rain);
void init_snow(RainSystem* rain);
void update_snow(RainSystem* rain);
void render_snow(const RainSystem* rain);
/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */