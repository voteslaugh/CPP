#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int getEnts(const size_t &k, const size_t &p) {
    if (k < 2) {
        return 0;
    }
    std::vector<size_t> num(k + 1);
    num[2] = 1;
    for (int i = 2; i < k; i++) {
        num[i + 1] = (num[i + 1] + num[i]) % p;
        if (2 * i <= k) {
            num[2 * i] = num[i];
        }
    }
    return num[k];
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    size_t k, p;
    in >> k >> p;
    out<<getEnts(k, p);
    return 0;
}