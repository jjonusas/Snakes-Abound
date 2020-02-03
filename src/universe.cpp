#include <stdlib.h>
#include <time.h>
#include <universe.h>
#include <game.h>

Universe::Universe(std::size_t width, std::size_t height,
                   std::size_t grid_ver, std::size_t grid_hor) 
    : _width(width),
    _height(height),
    _grid_ver(grid_ver),
    _grid_hor(grid_hor),
    _run(true) {
  _snake = Snake(this, width, height, grid_ver, grid_hor);

  // Temporary, will be set later on
  _rate = 100;
}

void Universe::Run(Controler *controler, Renderer *renderer) {

  CreateFood();

  unsigned int current_time, last_time = 0;
  // Enter the game loop
  while (_run) {
    current_time = SDL_GetTicks();
    if (current_time - last_time > _rate) {
      controler->UpdateDirection();
      _snake.Update(_food);
      renderer->Draw(_snake, _food);
      last_time = current_time;
    }
  }
}

void Universe::CreateFood() {
  srand(time(NULL));
  int ver_step = _height/_grid_ver;
  int hor_step = _width/_grid_hor;
  int x = (rand()%_grid_hor)*hor_step;
  int y = (rand()%_grid_ver)*ver_step;
  _food = {x, y, hor_step, ver_step};
}

void Universe::IncrementScore() {
  _game->IncrementScore();
}
