#include <stdio.h>

const char* TREE =
	R"(       *       )" "\n" 
	R"(       |       )" "\n"
	R"(      / \      )" "\n"
	R"(     /_ _\     )" "\n"
	R"(     /   \     )" "\n"
	R"(    /_   _\    )" "\n"
	R"(    /     \    )" "\n"
	R"(   /___ ___\   )" "\n"
	R"(______/|\______)" "\n";

int main() {
	printf("%s\n", TREE);
	return 0;
}
