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

    return lcs;
}

//with pruning
LCS_tuple AllPairsLCS_p(std::vector<std::string> S) {
    LCS_tuple lcs =  std::make_tuple("","",0);
    size_t temp;
    size_t &l = std::get<2>(lcs);
    for (size_t i = 0; i < S.size(); ++i) {
        if (l >= S[i].length()) {
            continue;
        }

        for (size_t j = 0; j < S.size(); ++j) {
            if (l >= S[j].length()) {
                continue;
            }

            temp = LCS_p(S[i], S[j], l);
            if (l < temp) {
                lcs = std::make_tuple(S[i],S[j], temp);
            }
        }
    }

    return lcs;
}

//with sorting
LCS_tuple AllPairsLCS_s(std::vector<std::string> S) {
    LCS_tuple lcs =  std::make_tuple("","",0);
    size_t temp;
    size_t &l = std::get<2>(lcs);
    
    std::sort(S.begin(), S.end(), [](const std::string &a, const std::string &b){return a.length() > b.length();});

    for (size_t i = 0; i < S.size(); ++i) {
        if (l >= S[i].length()) {
            break;
        }

        for (size_t j = 0; j < S.size(); ++j) {
            if (l >= S[j].length()) {
                break;
            }

            temp = LCS_p(S[i], S[j], l);
            if (l < temp) {
                lcs = std::make_tuple(S[i],S[j], temp);
            }
        }
    }

    return lcs;
}

//with preallocation
LCS_tuple AllPairsLCS_pab(std::vector<std::string> S) {
    LCS_tuple lcs =  std::make_tuple("","",0);
    size_t temp;
    size_t &l = std::get<2>(lcs);
    
    //Get length of longest string to preallocate tables;
    size_t maxLength = std::max_element(S.begin(), S.end(), [](const std::string &a, const std::string &b){return a.length() < b.length();})->length() + 1;
    
    //Preallocated P and D tables
    std::vector<size_t> D(maxLength*maxLength);
    std::vector<char> P(maxLength*maxLength);

    for (size_t i = 0; i < S.size(); ++i) {
        for (size_t j = 0; j < S.size(); ++j) {
            temp = LCS_pa(S[i], S[j], D, P);
            if (l < temp) {
                lcs = std::make_tuple(S[i],S[j], temp);
            }
        }
    }

    return lcs;

}

//with preallocation and pruning
LCS_tuple AllPairsLCS_pap(std::vector<std::string> S) {
    LCS_tuple lcs =  std::make_tuple("","",0);
    size_t temp;
    size_t &l = std::get<2>(lcs);

    //Get length of longest string to preallocate tables;
    size_t maxLength = std::max_element(S.begin(), S.end(), [](const std::string &a, const std::string &b){return a.length() < b.length();})->length() + 1;
    
    //Preallocated P and D tables
    std::vector<size_t> D(maxLength*maxLength);
    std::vector<char> P(maxLength*maxLength);


    for (size_t i = 0; i < S.size(); ++i) {
        if (l >= S[i].length()) {
            continue;
        }

        for (size_t j = 0; j < S.size(); ++j) {
            if (l >= S[j].length()) {
                continue;
            }

            temp = LCS_pap(S[i], S[j], l, D, P);
            if (l < temp) {
                lcs = std::make_tuple(S[i],S[j], temp);
            }
        }
    }

    return lcs;
}

//with preallocation and sorting
LCS_tuple AllPairsLCS_pas(std::vector<std::string> S) {
    LCS_tuple lcs =  std::make_tuple("","",0);
    size_t temp;
    size_t &l = std::get<2>(lcs);

    std::sort(S.begin(), S.end(), [](const std::string &a, const std::string &b){return a.length() > b.length();});

    //Get length of longest string to preallocate tables;
    size_t maxLength = S.front().length() + 1;    

    //Preallocated P and D tables
    std::vector<size_t> D(maxLength*maxLength);
    std::vector<char> P(maxLength*maxLength);


    for (size_t i = 0; i < S.size(); ++i) {
        if (l >= S[i].length()) {
            break;
        }

        for (size_t j = 0; j < S.size(); ++j) {
            if (l >= S[j].length()) {
                break;
            }

            temp = LCS_pap(S[i], S[j], l, D, P);
            if (l < temp) {
                lcs = std::make_tuple(S[i],S[j], temp);
            }
        }
    }

    return lcs;
}

//LCS
size_t LCS(const std::string &a, const std::string &b) {
    std::size_t rows = a.length() + 1;
    std::size_t cols = b.length() + 1;

    std::vector<size_t> D(rows*cols);
    std::vector<char> P(rows*cols);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (i == 0 || j == 0) {
                D[i*cols + j] = 0;
                P[i*cols + j] = 'N';
            } else if (a[i-1] == b[j-1]) {
                D[i*cols + j] = D[(i-1)*cols + (j-1)] + 1;
                P[i*cols + j] = 'D';
            } else {
                if (D[(i-1)*cols + j] > D[i*cols + (j-1)]) {
                    D[i*cols + j] = D[(i-1)*cols + j];
                    P[i*cols + j] = 'U';
                } else {
                    D[i*cols + j] = D[i*cols + (j-1)];
                    P[i*cols + j] = 'L';
                }
            }
        }
    }

    return D[rows*cols-1];
}

//with pruning
size_t LCS_p(const std::string &a, const std::string &b, const size_t &l) {
    std::size_t rows = a.length() + 1;
    std::size_t cols = b.length() + 1;

    std::vector<size_t> D(rows*cols);
    std::vector<char> P(rows*cols);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (i == 0 || j == 0) {
                D[i*cols + j] = 0;
                P[i*cols + j] = 'N';
            } else if (a[i-1] == b[j-1]) {
                D[i*cols + j] = D[(i-1)*cols + (j-1)] + 1;
                P[i*cols + j] = 'D';
            } else {
                if (D[(i-1)*cols + j] > D[i*cols + (j-1)]) {
                    D[i*cols + j] = D[(i-1)*cols + j];
                    P[i*cols + j] = 'U';
                } else {
                    D[i*cols + j] = D[i*cols + (j-1)];
                    P[i*cols + j] = 'L';
                }
            }
        }

        if (D[(i+1)*cols - 1] + rows - 1 - i <= l) {
            //Not enough characters left to beat l quit now
            return 0;
        }
    }

    return D[rows*cols-1];
}

//with preallocated table
size_t LCS_pa(const std::string &a, const std::string &b, std::vector<size_t> D, std::vector<char> P) {
    std::size_t rows = a.length() + 1;
    std::size_t cols = b.length() + 1;
    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (i == 0 || j == 0) {
                D[i*cols + j] = 0;
                P[i*cols + j] = 'N';
            } else if (a[i-1] == b[j-1]) {
                D[i*cols + j] = D[(i-1)*cols + (j-1)] + 1;
                P[i*cols + j] = 'D';
            } else {
                if (D[(i-1)*cols + j] > D[i*cols + (j-1)]) {
                    D[i*cols + j] = D[(i-1)*cols + j];
                    P[i*cols + j] = 'U';
                } else {
                    D[i*cols + j] = D[i*cols + (j-1)];
                    P[i*cols + j] = 'L';
                }
            }
        }
    }

    return D[rows*cols-1];
}

//with pruning and preallocated table
size_t LCS_pap(const std::string &a, const std::string &b, const size_t &l, std::vector<size_t> D, std::vector<char> P) {
    std::size_t rows = a.length() + 1;
    std::size_t cols = b.length() + 1;

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (i == 0 || j == 0) {
                D[i*cols + j] = 0;
                P[i*cols + j] = 'N';
            } else if (a[i-1] == b[j-1]) {
                D[i*cols + j] = D[(i-1)*cols + (j-1)] + 1;
                P[i*cols + j] = 'D';
            } else {
                if (D[(i-1)*cols + j] > D[i*cols + (j-1)]) {
                    D[i*cols + j] = D[(i-1)*cols + j];
                    P[i*cols + j] = 'U';
                } else {
                    D[i*cols + j] = D[i*cols + (j-1)];
                    P[i*cols + j] = 'L';
                }
            }
        }

        if (D[(i+1)*cols - 1] + rows - 1 - i <= l) {
            //Not enough characters left to beat l quit now
            return 0;
        }
    }

    return D[rows*cols-1];
}
