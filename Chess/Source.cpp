#include "Chess.h"
#include "Vector2.h"
#include <ctime>



int main() {
	std::srand(std::time(0)); // use current time as seed for random generator
	Chess chess(Vector2<float>(600, 600));
	chess.run();

	return 0;
}