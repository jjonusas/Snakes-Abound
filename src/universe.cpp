#include <iostream>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <universe.h>
#include <game.h>

Universe::Universe(std::size_t width,
                   std::size_t height,
                   std::size_t grid_ver,
                   std::size_t grid_hor, 
                   std::size_t offset) 
    : _width(width),
    _height(height),
    _grid_ver(grid_ver),
    _grid_hor(grid_hor),
    _offset(offset),
    _run(true) {
  _snake = Snake(this, width, height, grid_ver, grid_hor, offset);

  std::random_device rd;
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<> dis(50, 100);
  _rate = dis(gen);
}

void Universe::Run() {
  CreateFood();

  unsigned int current_time, last_time = 0;
  // Enter the game loop
  while (_run) {
    current_time = SDL_GetTicks();
    if (current_time - last_time > _rate) {
      _snake.Update(_food);
      last_time = current_time;
    }
  }
}

void Universe::CreateFood() {
  std::random_device rd;
  std::mt19937 gen(rd()); 

  int ver_step = _height/_grid_ver;
  int hor_step = _width/_grid_hor;

  std::uniform_int_distribution<> dis_hor(0, hor_step);
  int x = (dis_hor(gen))*hor_step+_offset;
  std::uniform_int_distribution<> dis_ver(0, ver_step);
  int y = (dis_ver(gen))*ver_step;
  std::lock_guard<std::mutex> lock(_mutex);
  _food = {x, y, hor_step, ver_step};
}

void Universe::IncrementScore() {
  _game->IncrementScore();
}

void Universe::Stop() {
  std::lock_guard<std::mutex> lock(_mutex);
  _run = false; 
}

Snake Universe::GetSnake() {
  std::lock_guard<std::mutex> lock(_mutex);
  return _snake;
}

SDL_Rect Universe::GetFood() {
  std::lock_guard<std::mutex> lock(_mutex);
  return _food;
}
