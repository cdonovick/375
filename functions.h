#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

typedef std::tuple<std::string, std::string, size_t>  LCS_tuple;

LCS_tuple AllPairsLCS_b(std::vector<std::string> S);  //base AllPairsLCS
LCS_tuple AllPairsLCS_p(std::vector<std::string> S);  //with pruning
LCS_tuple AllPairsLCS_s(std::vector<std::string> S);  //with sorting
LCS_tuple AllPairsLCS_pab(std::vector<std::string> S); //with preallocation
LCS_tuple AllPairsLCS_pap(std::vector<std::string> S); //with preallocation and pruning
LCS_tuple AllPairsLCS_pas(std::vector<std::string> S); //with preallocation and sorting

size_t LCS(const std::string &a, const std::string &b); //LCS
size_t LCS_p(const std::string &a, const std::string &b, const size_t &l); //LCS with pruning
size_t LCS_pa(const std::string &a, const std::string &b, std::vector<size_t> D, std::vector<char> P); //LCS with preallocated table
size_t LCS_pap(const std::string &a, const std::string &b, const size_t &l, std::vector<size_t> D, std::vector<char> P); //LCS with preallocated table and pruning
#endif
