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
    for (auto c = s.begin(); c != s.end(); ++c) { *c = rand_char('a', 'z', (seed*seed)^seed); }
    return s;
}

void test(size_t N, size_t M) {
    std::vector<std::string> S;
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    S.reserve(N);
    for (size_t i = 0; i < N; ++i) { 
        S.push_back(rand_str(M, seed));
    }
    
    auto S1 = S;
    auto S2 = S;
    auto S3 = S;
    auto S4 = S;
    auto S5 = S;
    auto S6 = S;

    std::cout << '1';
    auto r1 = AllPairsLCS_b(S1);  //base AllPairsLCS
    std::cout << ' ' << std::get<2>(r1) << std::endl;
    std::cout << '2';
    auto r2 = AllPairsLCS_p(S2);  //pruning
    std::cout << ' ' << std::get<2>(r2) << std::endl;
    std::cout << '3';
    auto r3 = AllPairsLCS_s(S3);  //sorting
    std::cout << ' ' << std::get<2>(r3) << std::endl;
    std::cout << '4';
    auto r4 = AllPairsLCS_pab(S4);  //pa-b
    std::cout << ' ' << std::get<2>(r4) << std::endl;
    std::cout << '5';
    auto r5 = AllPairsLCS_pap(S5);  //pa-p
    std::cout << ' ' << std::get<2>(r5) << std::endl;
    std::cout << '6';
    auto r6 = AllPairsLCS_pas(S6);  //pa-s
    std::cout << ' ' << std::get<2>(r6) << std::endl;
}
