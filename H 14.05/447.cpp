#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    long long  n, num = 1;
    in >> n;
    for (int i = 1; i <= n; i++) {
        num *= i; 
        while (num % 10 == 0) num /= 10;  
        num %= 1000000; 
    }
    out << num % 10;
    return 0;
}