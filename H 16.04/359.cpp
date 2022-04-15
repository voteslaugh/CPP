#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream out("output.txt");
    int n;
    input >> n;  
    int x = (n * n + 1) / 2;

    out << (x - 1) / 9 * 10 + (x - 1) % 9 + 1; 
    return 0;
}
