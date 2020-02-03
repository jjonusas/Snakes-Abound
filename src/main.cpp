#include <game.h>
#include <renderer.h>
#include <controler.h>

int main(int argc, char* argv[]) {
  // Initialise renderer, game universe, and controler
  Renderer renderer;
  Controler controler;
  Universe universe;

  // Initialise the game
  Game game(&renderer, &controler, &universe);
  controler.SetGameHandle(&game);
  universe.SetGameHandle(&game);

  // Play
  game.Run();

  printf("Your score was: %d \n", game.GetScore());
  return 0;
}
