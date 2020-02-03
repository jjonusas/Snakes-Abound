#ifndef CONTROLER_H
#define CONTROLER_H

#include <game.h>

class Game;

class Controler {
  public:
    Controler() {};
    void SetGameHandle(Game *game) { _game = game; };
    void UpdateDirection();

  private:
    Game *_game;
};
#endif
