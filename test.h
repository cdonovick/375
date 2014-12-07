#ifndef TEST_H
#define TEST_H
#include "functions.h"
#include <random>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

inline char rand_char(char min, char max, size_t seed = 0);

inline std::string rand_str(double avg_length, size_t seed = 0); 

void test(size_t N, size_t M);
#endif
