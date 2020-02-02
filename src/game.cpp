#include <game.h>

void Game::Run(){
  // Run the universe, will run parallel universes later on
  _universe->Run(_controler, _renderer); 
}
