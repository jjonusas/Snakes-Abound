#include <game.h>

Game::Game(Renderer *renderer, Controler *controler, Universe *universe)
        : _renderer(renderer),
          _controler(controler),
          _universe(universe),
          _score(0),
          _direction(Direction::DIR_RIGHT) {}

void Game::Run() {
  // Run the universe, will run parallel universes later on
  _universe->Run(_controler, _renderer); 
}

void Game::Quit() {
  _universe->Stop();
}
