#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>
#include <tuple>

typedef std::tuple<std::string, std::string, size_t>  LCS_tuple;

LCS_tuple AllPairsLCS_b(std::vector<std::string> S);  //base AllPairsLCS
LCS_tuple AllPairsLCS_p(std::vector<std::string> S);  //with pruning
LCS_tuple AllPairsLCS_s(std::vector<std::string> S);  //with sorting
LCS_tuple AllPairsLCS_pab(std::vector<std::string> S); //with preallocation
LCS_tuple AllPairsLCS_pap(std::vector<std::string> S); //with preallocation and pruning
LCS_tuple AllPairsLCS_pas(std::vector<std::string> S); //with preallocation and sorting

size_t LCS(std::string a, std::string b);               //LCS
size_t LCS(std::string a, std::string b, size_t best)    //LCS with pruning
size_t LCS_pa(std::string a, std::string b, size_t **d); //LCS with pre-allocated table
size_t LCS_pa(std::string a, std::string b, size_t best, size_t **d); //LCS with pre-allocated table and pruning
#endif
