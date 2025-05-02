#pragma once
#define GL_SILENCE_DEPRECATION
#ifdef _WINDOWS
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES 1
#define LEVEL1_WIDTH 20
#define LEVEL1_HEIGHT 15
#define ENEMY_COUNT 1

#include "Scene.h"
#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "Entity.h"
#include "Map.h"
#include "Utility.h"

class LevelA : public Scene {
private:
    // Level data arrays
    unsigned int LEVEL_1_DATA[LEVEL1_WIDTH * LEVEL1_HEIGHT];
    unsigned int BACKGROUND_MAP_DATA[LEVEL1_WIDTH * LEVEL1_HEIGHT];

    // Store the background map
    Map* m_background_map;

    // Additional level-specific state
    Entity* m_key;
    bool m_key_spawned = false;
    bool m_key_collected = false;
    glm::vec3 m_key_position;

    // Enemy state
    bool m_enemy_active = false;
    float m_enemy_timer = 0.0f;
    const float ENEMY_DELAY = 1.0f;
    bool m_enemy_following = false;
    glm::vec3 m_enemy_entry_position;

    // freeze effect
    bool m_game_frozen = false;
    float m_freeze_timer = 0.0f;
    const float FREEZE_DURATION = 0.5f;

    // Flag to track which type of freeze is happening
    bool m_show_escape_message = false;

    // Texture paths
    const char* SPRITESHEET_FILEPATH = "assets/player.png";
    const char* ENEMY_FILEPATH = "assets/enemy.png";
    const char* MAP_TILESET_FILEPATH = "assets/house_tileset.png";
    const char* BGM_FILEPATH = "assets/audio/dooblydoo.mp3";
    const char* JUMP_SFX_FILEPATH = "assets/audio/bounce.wav";
    const char* KEY_FILEPATH = "assets/key.png";

public:
    // Constructor/Destructor
    LevelA();
    ~LevelA();

    // Scene methods (overriding from Scene base class)
    void initialise() override;
    void update(float delta_time) override;
    void render(ShaderProgram* program) override;

    // Additional methods
    void process_input();
    void update_enemy(float delta_time);
    bool check_collision_in_direction(Entity* entity, glm::vec3 direction);

    // Add this method to access the game state
    GameState& get_state() { return m_game_state; }

    // Enemy state setters/getters
    void set_enemy_active(bool active) { m_enemy_active = active; }
    bool get_enemy_active() const { return m_enemy_active; }
    void set_enemy_following(bool following) { m_enemy_following = following; }
    bool get_enemy_following() const { return m_enemy_following; }
    void set_enemy_timer(float timer) { m_enemy_timer = timer; }
    void set_enemy_entry_position(glm::vec3 position) { m_enemy_entry_position = position; }
};
