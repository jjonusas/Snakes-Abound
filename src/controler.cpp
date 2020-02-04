#include <SDL.h>
#include <controler.h>

void Controler::UpdateDirection() {
  SDL_Event event;
  while(SDL_PollEvent(&event) != 0) {
    if (event.type == SDL_QUIT) {
      _game->Quit();
    } else {
      Game::Direction current_direction = _game->GetDirection();

      // Check if which keys were pressed. If the key is not the opposite to
      // the current direction, update the direction
      switch (event.key.keysym.sym) {
        case SDLK_DOWN:
          if (current_direction != Game::Direction::DIR_UP)
            _game->SetDirection(Game::Direction::DIR_DOWN);
          break;
        case SDLK_UP:
          if (current_direction != Game::Direction::DIR_DOWN)
            _game->SetDirection(Game::Direction::DIR_UP);
          break;
        case SDLK_LEFT:
          if (current_direction != Game::Direction::DIR_RIGHT)
            _game->SetDirection(Game::Direction::DIR_LEFT);
          break;
        case SDLK_RIGHT:
          if (current_direction != Game::Direction::DIR_LEFT)
            _game->SetDirection(Game::Direction::DIR_RIGHT);
          break;
      }
    }
  }
}


