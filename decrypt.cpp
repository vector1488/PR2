#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>
#include "decrypt.h"
#include "ssssen.h"
using namespace std;

int decrypt(string inFile) {
    string encFile = "encrypted.txt";
    string outFile = "decrypted.txt";

    vector<pair<int,int>> shares;
    cout << "Enter 3 parts of key (x y):\n";
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        shares.push_back({x, y});
    }

    int key = shamir_combine(shares);
    cout << "Key: " << key << endl;

    ifstream fin(encFile, ios::binary);
    if (!fin) {
        cerr << "Error " << encFile << endl;
        return 1;
    }
    vector<char> data((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    // XOR
    for (char &c : data) {
        c ^= key;
    }

    ofstream fout(outFile, ios::binary);
    fout.write(data.data(), data.size());
    fout.close();

    cout << "File saved: " << outFile << endl;
    return 0;
}

