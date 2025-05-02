
#include "WinScene.h"
#include "Utility.h"

WinScene::WinScene() {
    win_message = "YOU WIN!";
    restart_prompt = "PRESS ENTER TO PLAY AGAIN";
}

void WinScene::initialise() {
    // Load the font texture
    font_texture_id = Utility::load_texture("assets/font1.png");

    // Initialize game state
    m_game_state.next_scene_id = -1;
}

void WinScene::update(float delta_time) {
    // Nothing to update in the win scene
}

void WinScene::render(ShaderProgram* program) {
    glm::mat4 view_matrix = glm::mat4(1.0f);
    program->set_view_matrix(view_matrix);

    Utility::draw_text(program, font_texture_id, win_message, 0.4f, 0.2f, glm::vec3(-4.0f, 2.0f, 0.0f));

    Utility::draw_text(program, font_texture_id, restart_prompt, 0.25f, 0.05f, glm::vec3(-4.0f, 0.0f, 0.0f));
}