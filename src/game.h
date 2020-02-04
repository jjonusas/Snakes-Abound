#ifndef GAME_H
#define GAME_H

#include <snake.h>
#include <renderer.h>
#include <controler.h>
#include <universe.h>
#include <vector>

class Controler;

class Game {
  public:
    enum Direction {DIR_UP, DIR_DOWN, DIR_RIGHT, DIR_LEFT}; 

    Game(Renderer *renderer, Controler *controler, std::vector<std::shared_ptr<Universe>> &universes); 

    int GetScore() { return _score; };
    Direction GetDirection() { return _direction; };
    void SetDirection(Direction new_direction) { _direction = new_direction; };
    std::vector<std::shared_ptr<Universe>> GetUniverses() { return _universes; };

    void Run();
    void Quit();
    void IncrementScore() { _score++; };


  private:
    Renderer *_renderer;
    Controler *_controler;
    std::vector<std::shared_ptr<Universe>> _universes; 
    bool _run{true};

    Direction _direction;
    int _score;
};

#endif
