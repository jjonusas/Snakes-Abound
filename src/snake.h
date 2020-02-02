#ifndef SNAKE_H
#define SNAKE_H

#include <SDL.h>
#include <queue>

// Forward declaration
class Universe;

class Snake {
  public:
    enum Direction {DIR_UP, DIR_DOWN, DIR_RIGHT, DIR_LEFT};

    Snake(Universe *universe = nullptr); 

    std::deque<SDL_Rect> GetBody() { return _body; }; 
    Direction GetDirection() { return _direction; };
    void SetDirection(Direction direction) { _direction = direction; };

    void Update();

  private:
    std::deque<SDL_Rect> _body;
    Direction _direction;
    Universe *_universe;
};
#endif
