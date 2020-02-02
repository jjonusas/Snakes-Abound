#include <game.h>
#include <renderer.h>
#include <controler.h>

int main(int argc, char* argv[]) {
  // Initialise renderer, game universe, and controler
  Renderer renderer;
  Universe universe;
  Controler controler(&universe);

  // Initialise the game
  Game game(&renderer, &controler, &universe);

  // Play
  game.Run();

  return 0;
}
