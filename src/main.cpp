#include <game.h>
#include <renderer.h>
#include <controler.h>
#include <memory>
#include <vector>

int main(int argc, char* argv[]) {
  // Initialise renderer, game universe, and controler
  Renderer renderer(1280, 640);
  Controler controler;
  std::vector<std::shared_ptr<Universe>> universes = {};
  universes.emplace_back(std::make_shared<Universe>(640, 640, 32, 32, 0));
  universes.emplace_back(std::make_shared<Universe>(640, 640, 32, 32, 640));

  // Initialise the game
  Game game(&renderer, &controler, universes);
  renderer.SetGameHandle(&game);
  controler.SetGameHandle(&game);
  std::for_each(universes.begin(), universes.end(), [&game] (std::shared_ptr<Universe> &universe) {
                                                      universe->SetGameHandle(&game); });

  // Play
  game.Run();

  printf("Your score was: %d \n", game.GetScore());
  return 0;
}
