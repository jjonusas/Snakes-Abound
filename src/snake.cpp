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
    : _universe(universe) {
  
  int ver_step = height/grid_ver;
  int hor_step = width/grid_hor;

  _body = { {4*hor_step, int(grid_ver)*ver_step/2, hor_step, ver_step},
            {3*hor_step, int(grid_ver)*ver_step/2, hor_step, ver_step},
            {2*hor_step, int(grid_ver)*ver_step/2, hor_step, ver_step} };
}

void Snake::Update(SDL_Rect &food) {
  std::size_t height = _universe->GetHeight();
  std::size_t width = _universe->GetWidth();
  std::size_t ver_step = height / _universe->GetGridVer();
  std::size_t hor_step = width / _universe->GetGridHor();

  // Assumes that _body is always non empty
  SDL_Rect new_head = _body.front();

  switch (_universe->GetGameHandle()->GetDirection()) {
    case Game::Direction::DIR_UP:
      new_head.y = (new_head.y + height - ver_step ) % height; 
      break;
    case Game::Direction::DIR_DOWN:
      new_head.y = (new_head.y + height + ver_step) % height;
      break;
    case Game::Direction::DIR_RIGHT:
      new_head.x = (new_head.x + width + ver_step) % width; 
      break;
    case Game::Direction::DIR_LEFT:
      new_head.x = (new_head.x + width - ver_step) % width;
      break;
  }

  // Check for food or collision 
  auto first = _body.begin();
  auto last = _body.end();
  bool grow = false;
  for (; first != last; ++first) {
    if (*first == new_head) {
      _universe->Stop();
    } else if (*first == food) {
      grow = true;
      _universe->CreateFood();
      _universe->IncrementScore();
    }
  }
  _body.push_front(new_head);
  if (!grow) { _body.pop_back(); }
}
