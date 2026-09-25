#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "sfw.h"

class GameScene: public Scene{
	SFW_OBJECT(GameScene, Scene);

public:
    GameScene();
    ~GameScene();

    virtual void input_event(const Ref<InputEvent> &event);
	virtual void update(float delta);
	virtual void render();

    Ref<FrameBuffer> frame_buffer;

};

#endif