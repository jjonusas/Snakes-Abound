#include <algorithm>
#include <snake.h>
#include <universe.h>

// Auxilary function to compare SDL_Rects
bool operator==(SDL_Rect &a, SDL_Rect &b) {
  return  a.x == b.x && a.y == b.y && a.w == b.w && a.h == b.h;
}

// Passing the info about the size of the universe since the Snake constructor is
// called at the creation of Universe the data cannot be accessed via the pointer
Snake::Snake(Universe *universe, std::size_t width, std::size_t height,
             std::size_t grid_ver, std::size_t grid_hor) 
    : _universe(universe), _direction{DIR_RIGHT} {
  
  int ver_step = height/grid_ver;
  int hor_step = width/grid_hor;

  _body = { {4*hor_step, int(grid_ver)*ver_step/2, hor_step, ver_step},
            {3*hor_step, int(grid_ver)*ver_step/2, hor_step, ver_step},
            {2*hor_step, int(grid_ver)*ver_step/2, hor_step, ver_step} };
}

void Snake::Update() {
  std::size_t height = _universe->GetHeight();
  std::size_t width = _universe->GetWidth();
  std::size_t ver_step = height / _universe->GetGridVer();
  std::size_t hor_step = width / _universe->GetGridHor();

  // Assumes that _body is always non empty
  SDL_Rect new_head = _body.front();

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

  auto first = _body.begin();
  auto last = _body.end();
  for (; first != last; ++first) {
    if (*first == new_head) {
      _universe->Stop();
    }
  }
  _body.push_front(new_head);
  _body.pop_back();
}
