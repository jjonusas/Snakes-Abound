#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <snake.h>
#include <controler.h>
#include <renderer.h>

class Controler;
class Game;

class Universe {
  public:
    Universe(std::size_t width = 640, std::size_t height = 640,
             std::size_t grid_ver = 32, std::size_t grid_hor = 32, std::size_t offset = 0);

    Snake &GetSnake() { return _snake; };
    SDL_Rect GetFood() { return _food; };
    std::size_t GetWidth() { return _width; };
    std::size_t GetHeight() { return _height; };
    std::size_t GetGridVer() { return _grid_ver; };
    std::size_t GetGridHor() { return _grid_hor; };
    std::size_t GetOffset() { return _offset; };
    Game *GetGameHandle() { return _game; };
    void SetGameHandle(Game *game) { _game = game; };

    void CreateFood();
    void Run();
    void Stop() { _run = false; };
    void IncrementScore(); 

  private:
    bool _run{true};

    Snake _snake;
    SDL_Rect _food;

    Game *_game;

    std::size_t _width;
    std::size_t _height;
    std::size_t _grid_ver;
    std::size_t _grid_hor;
    std::size_t _offset;
    int _rate;
};

#endif
