#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
	int row;
	int col;
} Pos;

const char BALL = '0';
const int BALL_LIMIT = 3;
const float BALL_CHANCE = 0.3;
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
	R"(______|||______)" "\n";

int is(float max) {
	float chance = (float)rand() / (float)RAND_MAX;
	return chance < max;
}

int main(int argc, char** argv) {
	srand(time(NULL));

	int len = strlen(TREE);
	Pos balls[len * BALL_LIMIT];
	int ball_i = 0;

	for (int i = 0; i < len / WIDTH; i++) {
		int ci = -1;
		char c = '\0';
		int rand_cnt = 0;
		int is_start = 0;

		while (++ci < WIDTH) {
			c = TREE[i * WIDTH + ci];

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

			if (is(BALL_CHANCE)) {
				Pos pos = {
					.row = i,
					.col = ci
				};

				balls[ball_i] = pos;

				ball_i++;
				rand_cnt++;
			}
		}
	}

	printf("\033[1;32m%s\n\033[0m", TREE);

	int colors[] = { 37, 31, 32, 33 };
	for (int i = 0; ; i = (i + 1) % 4) {
		int j = 0;
		while (j < ball_i) {
			printf("\033[%d;%dH\033[1;%dm%c\033[0m",
		  		balls[j].row + 1,
		  		balls[j].col + 1,
		  		colors[i],
		  		BALL);
			j++;
		}

		if (argc >= 2) {
			if (strcmp(argv[1], "--frame") == 0) {
				printf("\033[%d;%dH", 10, 0);
				return 0;
			}
		}

		fflush(stdout);
		usleep(500000);
	}

	return 0;
}
