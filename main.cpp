#include "functions.h"
#include "test.h"
#include <string>

int main(int argc, char **argv) {
    if (argc != 3)
        return 1;
    test(std::stoi(argv[1]),std::stoi(argv[2]));
	return 0;
}

