#include "GSMenu.h"

int main() {
    std::srand(static_cast<unsigned>(time(NULL)));

	GSMenu gsmenu;
	gsmenu.run();

    return 0;
}
