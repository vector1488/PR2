#include <iostream>
#include <tuple> 
#include "modules.h"

using namespace std;

// Функция для нахождения обратного элемента a по модулю m. Работает почти как в прошлой программе NOD, но попроще устроена
// Возвращает -1, если обратный элемент не существует (если a и m не взаимно просты)
int mod(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1){
        return 0;
    }
    if (a == m){
        return 1;
    }
    while (a > 1) {
        int q = a / m; //само по себе частное от деления
        int t = m;

        m = a % m; // остаточек
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return (a == 1) ? x : -1; // НОД(a, m) != 1 -> обратного элемента нет
}

int modules() {
    int c, m;
    cout << "c^-1 mod m = d";
    cout << "Введите значения c и m: ";
    cin >> c >> m;
    int inv = mod(c, m);

    if (inv == -1) {
        cout << "Обратного элемента для " << c << " mod " << m << " не существует!\n";
    } else {
        cout << "Обратный элемент для " << c << " mod " << m << " = " << inv << "\n";
        cout << "Проверка: " << c << " * " << inv << " mod " << m << " = " << (c * inv) % m << "\n";
    }

    return 0;
}
