#include <iostream>
#include <vector>
#include "fraction.h"

// цепная дробь для p/q
std::vector<int> continuedFraction(int p, int q, int& m) {
    std::vector<int> cf;  // сюда пихаем частные
    while (q != 0) {
        int a = p / q;    // целая часть
        cf.push_back(a);
        int r = p % q;    // остаток
        p = q;
        q = r;
        
    }
    m = p; // последний ненулевой показатель и есть тот самый НОД
    return cf;
}


int fraction() {
    setlocale(LC_ALL, "RUS");
    int p, q, m = 0;
    std::cout << "Введите значения множителей a и b через пробел: " << std::endl;
    std::cin >> p >> q;

    std::vector<int> cf = continuedFraction(p, q, m);

    std::cout << p << "/" << q << " = [";
    for (size_t i = 0; i < cf.size(); i++) {
        std::cout << cf[i];
        if (i + 1 < cf.size())
            std::cout << ";";
    }
    std::cout << "]" << std::endl;
    std::cout << "НОД: " << m << std::endl;

    return 0;
}

