#include <thread>
#include <game.h>
#include <memory>

Game::Game(Renderer *renderer, Controler *controler, std::vector<std::shared_ptr<Universe>> &universes)
        : _renderer(renderer),
          _controler(controler),
          _universes(universes),
          _score(0),
          _direction(Direction::DIR_RIGHT) {}

void Game::Run() {
  
  std::vector<std::thread> threads = {};
  for(auto universe : _universes)
    threads.emplace_back(std::thread(&Universe::Run, universe));
  
  unsigned int current_time, last_time = 0;
  while(_run){
    current_time = SDL_GetTicks();
    if (current_time - last_time > 100) {
      _controler->UpdateDirection();
      _renderer->Draw();
      last_time = current_time;
    }
  }
  for(auto &trd : threads)
    trd.join();
}

void Game::Quit() {
  for (auto universe : _universes) 
    universe->Stop();
  std::lock_guard<std::mutex> lock(_mutex);
  _run = false;
}

void Game::IncrementScore() {
  std::lock_guard<std::mutex> lock(_mutex);
  _score++;
}

void Game::SetDirection(Direction new_direction) {
  std::lock_guard<std::mutex> lock(_mutex);
  _direction = new_direction; 
}

Game::Direction Game::GetDirection() {
  std::lock_guard<std::mutex> lock(_mutex);
  return _direction;
} 

std::vector<std::shared_ptr<Universe>> Game::GetUniverses() {
  std::lock_guard<std::mutex> lock(_mutex);
  return _universes; 
}
