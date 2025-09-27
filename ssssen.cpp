#include <iostream>
#include <vector>
#include <cstdint>
#include <random>
#include "ssssen.h"

using namespace std;

//const int PRIME = 257;

// Возведение в степень по модулю
int mod_pow(int a, int b, int c) {
    uint64_t result = 1;
    a = a % c;
    while(b>0){
        if(b%2 == 1){
            result = (result * a) % c;
        }
        a = (a * a) % c;
        b = b / 2;
    }
    return result;
}

// Деление секрета на части
vector<pair<int,int>> shamir_split(int secret, int n, int k) {
    vector<int> coeffs(k);
    coeffs[0] = secret;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, PRIME-1);
    for (int i = 1; i < k; i++) {
        coeffs[i] = dist(gen);
    }

    vector<pair<int,int>> shares;
    for (int x = 1; x <= n; x++) {
        uint64_t y = 0, pow_x = 1;
        for (int i = 0; i < k; i++) {
            y = (y + coeffs[i] * pow_x) % PRIME;
            pow_x = (pow_x * x) % PRIME;
        }
        shares.push_back({x, (int)y});
    }
    return shares;
}

// Восстановление секрета (Лагранж)
int shamir_combine(const vector<pair<int,int>>& shares) {
    uint64_t secret = 0;
    for (size_t i = 0; i < shares.size(); i++) {
        uint64_t xi = shares[i].first;
        uint64_t yi = shares[i].second;

        uint64_t num = 1, den = 1;
        for (size_t j = 0; j < shares.size(); j++) {
            if (i == j) continue;
            uint64_t xj = shares[j].first;
            num = (num * (-xj + PRIME)) % PRIME;
            den = (den * (xi - xj + PRIME)) % PRIME;
        }
        // Обратный элемент
        uint64_t inv = mod_pow(den, PRIME-2, PRIME);
        uint64_t term = yi * num % PRIME * inv % PRIME;
        secret = (secret + term) % PRIME;
    }
    return (int)secret;
}
