#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdint>
#include "encrypt.h"
#include "ssssen.h"


using namespace std;


// Генерация случайного ключа
int generate_key() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 255);
    return dist(gen);
}


int encrypt(string inFile) {
    string outFile = "encrypted.txt";

    ifstream fin(inFile, ios::binary);
    if (!fin) {
        cerr << "Не удалось открыть файл " << inFile << endl;
        return 1;
    }
    vector<char> data((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    int key = generate_key();
    cout << "Случайный ключ: " << key << endl;

    // Разбиваем ключ
    int n = 5, k = 3;
    auto shares = shamir_split(key, n, k);

    cout << "Секрет разделен на части (для n=" << n << ", k=" << k << "):" << endl;
    for (auto &sh : shares) {
        cout << "  (" << sh.first << ", " << sh.second << ")" << endl;
    }

    // Шифруем XOR
    for (char &c : data) {
        c ^= key;
    }

    ofstream fout(outFile, ios::binary);
    fout.write(data.data(), data.size());
    fout.close();

    cout << "Файл зашифрован и сохранен в " << outFile << endl;
    return 0;
}

