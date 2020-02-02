#ifndef CONTROLER_H
#define CONTROLER_H

#include <universe.h>
#include <snake.h>

class Controler {
  public:
    Controler(Universe *universe) : _universe(universe) {};
    void UpdateSnakeDirection();

  private:
    // This will be a list of universes later on
    Universe *_universe;
};
#endif
