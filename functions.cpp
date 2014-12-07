#include "functions.h"

//base AllPairsLCS
LCS_tuple AllPairsLCS_b(std::vector<std::string> S) {
    LCS_tuple lcs =  std::make_tuple("","",0);
    size_t temp;
    size_t &l = std::get<2>(lcs);
    for (size_t i = 0; i < S.size(); ++i) {
        for (size_t j = 0; j < S.size(); ++j) {
            temp = LCS(S[i], S[j]);
            if (l < temp) {
                lcs = std::make_tuple(S[i],S[j], temp);
            }
        }
    }

    return best;
}

//with pruning
LCS_tuple AllPairsLCS_p(std::vector<std::string> S) {
    LCS_tuple lcs =  std::make_tuple("","",0);
    size_t temp;
    size_t &l = std::get<2>(lcs);
    for (size_t i = 0; i < S.size(); ++i) {
        if (l > S[i].length()) {
            continue;
        }

        for (size_t j = 0; j < S.size(); ++j) {
            if (l > S[j].length()) {
                continue;
            }

            temp = LCS_p(S[i], S[j]);
            if (l < temp) {
                lcs = std::make_tuple(S[i],S[j], temp);
            }
        }
    }

    return best;
}

//with sorting
LCS_tuple AllPairsLCS_s(std::vector<std::string> S) {
    LCS_tuple lcs =  std::make_tuple("","",0);
    size_t temp;
    size_t &l = std::get<2>(lcs);
    
    std::sort(S.begin(), S.end(), [](std::string a, std::string b){return a.length() > b.length()});

    for (size_t i = 0; i < S.size(); ++i) {
        if (l > S[i].length()) {
            break;
        }

        for (size_t j = 0; j < S.size(); ++j) {
            if (l > S[j].length()) {
                break;
            }

            temp = LCS_p(S[i], S[j]);
            if (l < temp) {
                lcs = std::make_tuple(S[i],S[j], temp);
            }
        }
    }

    return best;
}

//with preallocation
LCS_tuple AllPairsLCS_pab(std::vector<std::string> S) {
    LCS_tuple lcs =  std::make_tuple("","",0);
    size_t temp;
    size_t &l = std::get<2>(lcs);
    
    //Get length of longest string to preallocate tables;
    size_t maxLength = std::max_element(S.begin(), S.end(), [](std::string a, std::string b){return a.length() < b.length()}).length();
    
    //
    std::vector<size_t> D(maxLength*maxLength);
    std::vector<char> P(maxLength*maxLength);

    for (size_t i = 0; i < S.size(); ++i) {
        for (size_t j = 0; j < S.size(); ++j) {
            temp = LCS(S[i], S[j]);
            if (l < temp) {
                lcs = std::make_tuple(S[i],S[j], temp);
            }
        }
    }

    return best;

}

//with preallocation and pruning
LCS_tuple AllPairsLCS_pap(std::vector<std::string> S) {
    LCS_tuple best =  std::make_tuple("","",0);
    return best;
}

//with preallocation and sorting
LCS_tuple AllPairsLCS_pas(std::vector<std::string> S) {
    LCS_tuple best =  std::make_tuple("","",0);
    return best;
}

//LCS
size_t LCS(std::string a, std::string b) {
    return 0;
}

//with pruning
size_t LCS_p(std::string a, std::string b, size_t best) {
    return 0;
}

//with preallocated table
size_t LCS_pa(std::string a, std::string b, std::vector<size_t> D) {
    return 0;
}

//with pruning and preallocated table
size_t LCS_pap(std::string a, std::string b, size_t best, std::vector<size_t> D) {
    return 0;
}
