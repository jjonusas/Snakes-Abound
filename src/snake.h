#ifndef SNAKE_H
#define SNAKE_H

#include <SDL.h>
#include <queue>

// Forward declaration
class Universe;

class Snake {
  public:
    Snake(Universe *universe = nullptr, std::size_t width = 640, std::size_t
          height = 640, std::size_t grid_ver = 32, std::size_t grid_hor = 32); 

    std::deque<SDL_Rect> GetBody() { return _body; }; 

    void Update(SDL_Rect &food);

  private:
    std::deque<SDL_Rect> _body;
    Universe *_universe;
};
#endif
