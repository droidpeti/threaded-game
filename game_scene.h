#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "sfw/sfw.h"
#include "entities/player.h"

class GameScene: public Scene{
	SFW_OBJECT(GameScene, Scene);

public:
    GameScene();
    ~GameScene();

    virtual void input_event(const Ref<InputEvent> &event);
	virtual void update(float delta);
	virtual void render();

private:
    Ref<FrameBuffer> frame_buffer;
    Ref<Player> player;

    // input
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
};

#endif