#include <SDL.h>
#include <controler.h>

void Controler::UpdateSnakeDirection() {
  SDL_Event event;
  while(SDL_PollEvent( &event) != 0) {
    if (event.type == SDL_QUIT) {
      _universe->Stop();
    } else {
      Snake::Direction current_direction = _universe->GetSnake().GetDirection();

      // Check if which keys were pressed. If the key is not the opposite to
      // the current direction, update the direction
      switch (event.key.keysym.sym) {
        case SDLK_DOWN:
          if (current_direction != Snake::Direction::DIR_UP)
            _universe->GetSnake().SetDirection(Snake::Direction::DIR_DOWN);
          break;
        case SDLK_UP:
          if (current_direction != Snake::Direction::DIR_DOWN)
            _universe->GetSnake().SetDirection(Snake::Direction::DIR_UP);
          break;
        case SDLK_LEFT:
          if (current_direction != Snake::Direction::DIR_RIGHT)
            _universe->GetSnake().SetDirection(Snake::Direction::DIR_LEFT);
          break;
        case SDLK_RIGHT:
          if (current_direction != Snake::Direction::DIR_LEFT)
            _universe->GetSnake().SetDirection(Snake::Direction::DIR_RIGHT);
          break;
      }
    }
  }
}
