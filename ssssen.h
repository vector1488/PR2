#pragma once
#include <vector>
#include <utility>

const int PRIME = 257;

int mod_pow(int base, int exp, int mod);
std::vector<std::pair<int,int>> shamir_split(int secret, int n, int k);
int shamir_combine(const std::vector<std::pair<int,int>>& shares);
