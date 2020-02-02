#include <universe.h>

Universe::Universe(std::size_t width, std::size_t height,
                   std::size_t grid_ver, std::size_t grid_hor) 
    : _width(width),
    _height(height),
    _grid_ver(grid_ver),
    _grid_hor(grid_hor),
    _run(true) {
  _snake = Snake(this);
  // Temporary, will be set later on
  _rate = 100;
}

void Universe::Run(Controler *controler, Renderer *renderer) {
  unsigned int current_time, last_time = 0;

  while (_run) {
    current_time = SDL_GetTicks();
    if (current_time - last_time > _rate) {
      controler->UpdateSnakeDirection();
      _snake.Update();
      renderer->Draw(_snake);
      last_time = current_time;
    }
  }
}
