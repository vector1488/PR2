#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>
using namespace std;

const int PRIME = 257;

int mod_pow(int a, int b, int c) {
    uint64_t result = 1;
    a %= c;
    while (b > 0) {
        if (b & 1) result = (result * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return (int)result;
}

// Восстановление секрета по любым 3 долям
int shamir_combine(const vector<pair<int,int>>& shares) {
    uint64_t secret = 0;
    for (size_t i = 0; i < shares.size(); i++) {
        uint64_t xi = shares[i].first;
        uint64_t yi = shares[i].second;

        uint64_t num = 1, den = 1;
        for (size_t j = 0; j < shares.size(); j++) {
            if (i == j) continue;
            uint64_t xj = shares[j].first;
            num = (num * (PRIME - xj)) % PRIME;
            den = (den * (xi - xj + PRIME)) % PRIME;
        }
        uint64_t inv = mod_pow(den, PRIME-2, PRIME);
        uint64_t term = yi * num % PRIME * inv % PRIME;
        secret = (secret + term) % PRIME;
    }
    return (int)secret;
}

int main() {
    cout << "Атака на Shamir (5,3). Введите 3 доли (x y):\n";
    vector<pair<int,int>> shares;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        shares.push_back({x,y});
    }

    int key = shamir_combine(shares);
    cout << "Восстановленный ключ: " << key << endl;
    return 0;
}

