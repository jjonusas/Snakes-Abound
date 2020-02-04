#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <mutex>
#include <snake.h>
#include <controler.h>
#include <renderer.h>

class Controler;
class Game;

class Universe {
  public:
    Universe(std::size_t width = 640, std::size_t height = 640,
             std::size_t grid_ver = 32, std::size_t grid_hor = 32, std::size_t offset = 0);

    Snake GetSnake();
    SDL_Rect GetFood();
    std::size_t GetWidth() { return _width; };
    std::size_t GetHeight() { return _height; };
    std::size_t GetGridVer() { return _grid_ver; };
    std::size_t GetGridHor() { return _grid_hor; };
    std::size_t GetOffset() { return _offset; };
    Game *GetGameHandle() { return _game; };
    void SetGameHandle(Game *game) { _game = game; };

    void CreateFood();
    void Run();
    void Stop();
    void IncrementScore(); 

  private:
    bool _run{true};

    Snake _snake;
    SDL_Rect _food;

    Game *_game;

    std::size_t const _width;
    std::size_t const _height;
    std::size_t const _grid_ver;
    std::size_t const _grid_hor;
    std::size_t const _offset;
    int _rate;
    std::mutex _mutex;
};

#endif
