#include "GSMenu.h"

int main() {
  std::srand(static_cast<unsigned>(time(NULL)));
	sf::Music music;
	if (!music.openFromFile("../Data/Music/music.wav"))
		return -1; // error
	music.play();
	music.setLoop(true);
	GSMenu gsmenu;

	gsmenu.run();

  return 0;
}
