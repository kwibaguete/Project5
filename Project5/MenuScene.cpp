/**
* Author: Belinda Weng
* Assignment: your house
* Date due: 5/2/2025, 2:00pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#include "MenuScene.h"
#include "Utility.h"

MenuScene::MenuScene() {
    game_title = "your home";
    start_prompt = "PRESS ENTER TO START";
}

void MenuScene::initialise() {
    // Load the font texture
    font_texture_id = Utility::load_texture("assets/font1.png");

    // Initialize game state
    m_game_state.next_scene_id = -1;
}

void MenuScene::update(float delta_time) {
    process_input();
}

void MenuScene::process_input() {
    const Uint8* key_state = SDL_GetKeyboardState(NULL);
    if (key_state[SDL_SCANCODE_RETURN] || key_state[SDL_SCANCODE_KP_ENTER]) {
        // Set next scene to Level A
        m_game_state.next_scene_id = 0;
    }
}

void MenuScene::render(ShaderProgram* program) {
    glm::mat4 view_matrix = glm::mat4(1.0f);
    program->set_view_matrix(view_matrix);

    Utility::draw_text(program, font_texture_id, game_title, 0.4f, 0.2f, glm::vec3(-4.0f, 2.0f, 0.0f));

    Utility::draw_text(program, font_texture_id, start_prompt, 0.25f, 0.15f, glm::vec3(-4.0f, 0.0f, 0.0f));
}
