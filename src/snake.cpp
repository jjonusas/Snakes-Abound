#include <snake.h>
#include <universe.h>

// Temporary constructor for testing
Snake::Snake(Universe *universe) : _universe(universe), _direction{DIR_DOWN}
{
  _body = {{20, 60, 20, 20}, {40, 60, 20, 20}, {60, 60, 20, 20}, {60, 80, 20, 20}, {60, 100, 20, 20}};
}

void Snake::Update() {
  std::size_t height = _universe->GetHeight();
  std::size_t width = _universe->GetWidth();
  std::size_t ver_step = height / _universe->GetGridVer();
  std::size_t hor_step = width / _universe->GetGridHor();

  // Assumes that _body is always non empty
  SDL_Rect new_head = _body[0];

  switch (_direction) {
    case DIR_UP:
      new_head.y = (new_head.y + height - ver_step ) % height; 
      break;
    case DIR_DOWN:
      new_head.y = (new_head.y + height + ver_step) % height;
      break;
    case DIR_RIGHT:
      new_head.x = (new_head.x + width + ver_step) % width; 
      break;
    case DIR_LEFT:
      new_head.x = (new_head.x + width - ver_step) % width;
      break;
  }
  _body.push_front(new_head);
  _body.pop_back();
}
