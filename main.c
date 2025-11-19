#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int BALL_LIMIT = 2;
const int WIDTH = 16;
char TREE[] =
	R"(       *       )" "\n" 
	R"(       |       )" "\n"
	R"(      / \      )" "\n"
	R"(     /_ _\     )" "\n"
	R"(     /   \     )" "\n"
	R"(    /_   _\    )" "\n"
	R"(    /     \    )" "\n"
	R"(   /___ ___\   )" "\n"
	R"(______/|\______)" "\n";

int is(int max) {
	return rand() % max >= max - 1;
}

int main() {
	srand(time(NULL));

	for (int i = 0; i < strlen(TREE); i += WIDTH) {
		int ci = -1;
		char c = '\0';
		int rand_cnt = 0;
		int is_start = 0;

		while (++ci < WIDTH) {
			c = TREE[i + ci];

			if (c == '/') {
				is_start = 1;
				continue;
			}

			if (!is_start) {
				continue;
			}

			if (c == '\\') {
				break;
			}

			if (rand_cnt >= BALL_LIMIT) {
				break;
			}

			if (is(4)) {
				TREE[i + ci] = '*';
			}
		}
	}
	
	printf("%s\n", TREE);
	return 0;
}
