#include "sfw.h"

#include "game_application.h"

int main(){
    Application* game = memnew(GameApplication());

    game->start_main_loop();

    memdelete(game);

    return 0;
}
