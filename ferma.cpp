#include<iostream>
#include<cstdint>
#include<random>
#include<vector>
#include<cmath>
#include"ferma.h"

namespace { // область видимости этих переменных - только этот файл
    std::random_device rd("/dev/random");
    std::mt19937_64 random_generator { rd() };
    std::vector<int> eratosthenes_primes; // тк остальные функции работают с уже сгенерированными числами, мы пихнули вектор сюда
}


std::vector<int> sieve_of_eratosthenes(int limit) {
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

uint64_t powerMod(uint64_t a, uint64_t b, uint64_t c){
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

bool isPrime(uint64_t p){
    int k = 0;
    auto sieve = sieve_of_eratosthenes(p*10);
    for(const auto &x : sieve){
        if(p == x){
            k+=1;
        }
    }
    if(k>0){
        return true;
    } else {
        return false;
    }
}

bool checkFerma(uint64_t a, uint64_t x, uint64_t p){
    if(a % p == 0){
        return true;
    }
    return powerMod(a, p-1, p) == 1;
}

uint64_t calculateFerma(uint64_t a, uint64_t x, uint64_t p){
    if(a % p == 0){
        return 0;
    }
    x = x %(p-1);
    return powerMod(a, x, p);
}

int ferma(){
    setlocale(LC_ALL, "RUS");
    uint64_t a, x, p;
    std::cout << "Введите числа для a^x mod p (примечание - число p должно быть простым): " << std::endl;
    std::cin >> a >> x >> p;
    if(!isPrime(p)){
        std::cout << "Число p не простое. Запустите программу заново." <<std::endl;
        return 0;
    }
    if(!checkFerma(a,x,p)){
        std::cout << "Теорема не выполняется. Запустите программу заново." << std::endl;
        return 0;
    }
    uint64_t res = calculateFerma(a, x, p);
    if(res>=0){
        std::cout << "Результат: " << res << std::endl;
    } else {
        std::cout << "Ошибка. Введите другие значения." << std::endl;
    }
    return 0;
}    
    
    
