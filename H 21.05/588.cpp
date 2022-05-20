#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    if (n == 1 || n == 2 || n == 3 || n == 6) {
        out << -1;
        return 0;
    }
    if (n == 4) {
        out << 2 << endl << 1 << endl << 0 << endl << 1;
        return 0;
    }
    if (n == 5) {
        out << 1 << endl << 2 << endl << 0 << endl << 0 << endl << 2;
        return 0;
    }
    vector<int> a(n + 1);
    a[1] = 2;
    a[2] = 1;
    a[n - 4] = 1;
    a[n] = n - 4;
    for (int i = 1; i < a.size(); ++i)
        out << a[i] << endl;
    return 0;
}