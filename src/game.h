#ifndef GAME_H
#define GAME_H

#include <snake.h>
#include <renderer.h>
#include <controler.h>
#include <universe.h>

class Controler;

class Game {
  public:
    enum Direction {DIR_UP, DIR_DOWN, DIR_RIGHT, DIR_LEFT}; 

    Game(Renderer *renderer, Controler *controler, Universe *universe); 

    int GetScore() { return _score; };
    Direction GetDirection() { return _direction; };
    void SetDirection(Direction new_direction) { _direction = new_direction; };

    void Run();
    void Quit();
    void IncrementScore() { _score++; };


  private:
    Renderer *_renderer;
    Controler *_controler;
    Universe *_universe; 

    Direction _direction;
    int _score;
};

#endif
