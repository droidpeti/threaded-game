#include "game_scene.h"


GameScene::GameScene(){
    Renderer::initialize();
    //GUI::initialize();
    frame_buffer.instance();
    frame_buffer->create(800, 600);
    player.instance();
    player->Init(Vector2(0, 0), Vector2(50, 50), 300);
}

GameScene::~GameScene(){
    //GUI::destroy();
    Renderer::destroy();
}

void GameScene::input_event(const Ref<InputEvent> &event){
    Ref<InputEventKey> key = event;

    if (key.is_valid()) {
        if (key->is_echo()){
            return;
        }

        bool pressed = key->is_pressed();

        switch (key->get_scancode()) {
            case KEY_W: up    = pressed; break;
            case KEY_S: down  = pressed; break;
            case KEY_A: left  = pressed; break;
            case KEY_D: right = pressed; break;
            default: break;
        }
    }
}

void GameScene::update(float delta){
    Vector2 moveDirection {
        (float)right - (float)left,
        (float)down - (float)up
    };

    player->SetMoveDirection(moveDirection);
    player->Update(delta);
}

void GameScene::render() {
    Renderer* r = Renderer::get_singleton();
    

    r->clear_screen(Color(0.08f, 0.08f, 0.08f));
    r->camera_2d_projection_set_to_window();

    float winW = AppWindow::get_singleton()->get_width();
    float winH = AppWindow::get_singleton()->get_height();

    Vector2 screen_center(winW / 2.0f, winH / 2.0f);

    Vector2 player_center = player->position + (player->size * 0.5f);

    Transform2D camera;
    camera.translate(screen_center - player_center);

    r->camera_2d_push_model_view_matrix(camera);

    r->draw_line_rect(Rect2(100, 100, 40, 40));
    r->draw_line_rect(Rect2(150, 100, 40, 40), Color(1, 1, 0));
    r->draw_line_rect(Rect2(200, 100, 40, 40), Color(1, 1, 1), 4);

    // draw player
    r->draw_rect(Rect2(player->position.x, player->position.y, player->size.x, player->size.y), Color(1, 1, 0));

    r->camera_2d_pop_model_view_matrix();
}
