#include "game_scene.h"


GameScene::GameScene(){
    Renderer::initialize();
    //GUI::initialize();
    frame_buffer.instance();
    frame_buffer->create(800, 600);
}

GameScene::~GameScene(){
    //GUI::destroy();
    Renderer::destroy();
}

void GameScene::input_event(const Ref<InputEvent> &event){

}

void GameScene::update(float delta){

}

void GameScene::render(){

    //AppWindow::get_singleton()->reset_viewport();

    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    Renderer* r = Renderer::get_singleton();

    r->clear_screen(Color());
    r->camera_2d_projection_set_to_window();

    r->draw_line_rect(Rect2(100, 100, 40, 40));
	r->draw_line_rect(Rect2(150, 100, 40, 40), Color(1, 1, 0));
	r->draw_line_rect(Rect2(200, 100, 40, 40), Color(1, 1, 1), 4);

}
