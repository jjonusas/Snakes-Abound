#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <snake.h>

class Game;

class Renderer {
  public:
    Renderer(std::size_t w = 640, std::size_t h = 640);
    ~Renderer();

    // Renderer should not be moved or copied
    Renderer(Renderer &) = delete;
    Renderer &operator=(Renderer &) = delete;
    Renderer(Renderer &&) = delete;
    Renderer &operator=(Renderer &&) = delete; 

    void SetGameHandle(Game *game) { _game = game; }

    void Draw();

  private:
    SDL_Window* _window = NULL;
    SDL_Renderer* _renderer = NULL;

    Game *_game;

    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
};

#endif
