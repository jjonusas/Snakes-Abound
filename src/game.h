#ifndef GAME_H
#define GAME_H

#include <snake.h>
#include <renderer.h>
#include <controler.h>
#include <universe.h>

class Game {
  public:
    Game(Renderer *renderer, Controler *controler, Universe *universe) 
        : _renderer(renderer), _controler(controler), _universe(universe) {};
    void Run();

  private:
    Renderer *_renderer;
    Controler *_controler;
    Universe *_universe; 
};

#endif
