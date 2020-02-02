#include <SDL.h>
#include <renderer.h>

Renderer::Renderer(std::size_t width, std::size_t height) 
    : SCREEN_WIDTH(width), SCREEN_HEIGHT(height) { 

  // Initialise SDL and create a SDL renderer
  if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
    printf("SDL could not be initialised. SDL Error: %s\n", SDL_GetError());
  } else {
    _window = SDL_CreateWindow("Snakes Abound",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
  }
}

void Renderer::Draw(Snake &snake) {

  // Set the background colour
  SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(_renderer);

  // Set the colour of the body and draw the body
  SDL_SetRenderDrawColor(_renderer, 0x31, 0x12, 0xFA, 0xAF);
  for (SDL_Rect piece: snake.GetBody()) {
    SDL_RenderFillRect(_renderer, &piece);
  }
  SDL_RenderPresent(_renderer);
}

Renderer::~Renderer()
{
  //Destroy renderer 
  SDL_DestroyRenderer(_renderer);
  _renderer = NULL;

  //Destroy window
  SDL_DestroyWindow(_window);
  _window = NULL;


  //Quit SDL subsystems
  SDL_Quit();
}
