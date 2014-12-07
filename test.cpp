#include "test.h"
inline char rand_char(char min, char max, size_t seed) {
    std::uniform_int_distribution<char> dist(min, max);
    static std::default_random_engine gen(seed);
    return dist(gen);
}

inline std::string rand_str(double avg_length, size_t seed) {
    std::poisson_distribution<size_t> dist(avg_length);
    static std::default_random_engine gen(seed);
    std::string s(dist(gen), 0);
    for (auto c = s.begin(); c != s.end(); ++c) { *c = rand_char('a', 'z', seed); }
    return s;
}

void test(size_t N) {
    std::vector<std::string> S;
    S.reserve(N);
    for (size_t i = 0; i < N; ++i) { 
        S.push_back(rand_str(10));
    }
   
    std::cout << '1' << std::endl;
    auto r1 = AllPairsLCS_b(S);  //base AllPairsLCS
    std::cout << '2' << std::endl;
    auto r2 = AllPairsLCS_p(S);  //with pruning
    std::cout << '3' << std::endl;
    auto r3 = AllPairsLCS_s(S);  //with sorting
    std::cout << '4' << std::endl;
    auto r4 = AllPairsLCS_pab(S); //with preallocation
    std::cout << '5' << std::endl;
    auto r5 = AllPairsLCS_pap(S); //with preallocation and pruning
    std::cout << '6' << std::endl;
    auto r6 = AllPairsLCS_pas(S); //with preallocation and sorting

    assert(0               != std::get<2>(r1));
    assert(std::get<2>(r1) == std::get<2>(r2));
    assert(std::get<2>(r2) == std::get<2>(r3));
    assert(std::get<2>(r3) == std::get<2>(r4));
    assert(std::get<2>(r4) == std::get<2>(r5));
    assert(std::get<2>(r5) == std::get<2>(r6));
}
