#pragma once
#define GL_SILENCE_DEPRECATION
#ifdef _WINDOWS
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES 1
#define LEVEL3_WIDTH 20
#define LEVEL3_HEIGHT 15
#define ENEMY_COUNT 3

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

class LevelC : public Scene {
private:
    // Level data arrays
    unsigned int LEVEL_3_DATA[LEVEL3_WIDTH * LEVEL3_HEIGHT];
    unsigned int BACKGROUND_MAP_DATA[LEVEL3_WIDTH * LEVEL3_HEIGHT];

    // Additional level-specific state
    Entity* m_key;
    bool m_key_spawned = false;
    bool m_key_collected = false;
    glm::vec3 m_key_position;

    // freeze effect
    bool m_game_frozen = false;
    float m_freeze_timer = 0.0f;
    const float FREEZE_DURATION = 1.0f;

    // Texture paths
    const char* SPRITESHEET_FILEPATH = "assets/player.png";
    const char* ENEMY_FILEPATH = "assets/enemy.png";
    const char* MAP_TILESET_FILEPATH = "assets/house_tileset.png";
    const char* BGM_FILEPATH = "assets/audio/dooblydoo.mp3";
    const char* JUMP_SFX_FILEPATH = "assets/audio/bounce.wav";
    const char* KEY_FILEPATH = "assets/final_key.png";

public:
    // Constructor/Destructor
    LevelC();
    ~LevelC();

    // Scene methods (overriding from Scene base class)
    void initialise() override;
    void update(float delta_time) override;
    void render(ShaderProgram* program) override;

    // Additional methods
    void process_input();

    // Add this method to access the game state
    GameState& get_state() { return m_game_state; }

    // Add this method to get the key collected state
    bool get_key_collected() const { return m_key_collected; }
};
