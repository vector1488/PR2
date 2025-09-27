#include <iostream>
#include <cmath>
#include <tuple>
#include "extevklid.h"

using namespace std;

// Берём псевдокод из теории, предоставленной в курсе на DiSpace
// Функция возвращает кортеж (НОД(a, b), u, v) такие, что a*u + b*v = НОД(a, b)
tuple<int, int, int> extended_gcd(int a, int b) {
    // Инициализация начальных значений (просто пихаем всё, что написано в псевдокоде в начальные значения)
    int x1 = a, y1 = b;
    int x2 = 1, y2 = 0;
    int x3 = 0, y3 = 1;
    
    while (y1 != 0) {
        int q = x1 / y1;
        
        int t1 = x1 % y1; // новые значения для T (T в виде отдельных знаков)
        int t2 = x2 - q * y2;
        int t3 = x3 - q * y3;
        
        // Обновление X и Y
        x1 = y1; x2 = y2; x3 = y3;
        y1 = t1; y2 = t2; y3 = t3;
    }
    
    return make_tuple(x1, x2, x3);
}
int find_d(int m, int n){
    int nod, x, y;
    tie(nod, x, y) = extended_gcd(m, n); // присваиваем кортежу значения, полученные в ходе выполнения функции extended_gcd
    
    if (nod != 1) {
        throw runtime_error("Обратного элемента не существует");
    } else {
        return (x % n + n) % n; //результат должен быть положительным
    }
}

int extevklid() {
    int c, m;
    cout << "Введите c и m (для уравнения c*d mod m = 1): ";
    cin >> c >> m;
    
    try {
        int d = find_d(c, m);
        cout << "Обратный элемент d = " << d << endl;
        cout << "Проверка: " << c << "*" << d << " mod " << m << " = " << (c * d) % m << ", результат деления: " << (c*d -1) / m << endl;
    } catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    return 0;
}
