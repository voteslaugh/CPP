#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, numb = 0;
    in >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; ++i)
        a[i] = new int[n];

    int stop = (n % 2 == 0) ? n / 2 : n / 2 + 1;

    for (int i = 0; i < stop; i++) {
        for (int j = i; j < n - i; j++) 
            a[i][j] = ++numb;
        for (int j = i + 1; j < n - i; j++) 
            a[j][n - i - 1] = ++numb;
        for (int j = i + 1; j < n - i; j++) 
            a[n - i - 1][n - j - 1] = ++numb;
        for (int j = i + 1; j < n - i - 1; j++) 
            a[n - j - 1][i] = ++numb;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << a[i][j] << " ";
        }
        out << endl;
    }

    return 0;
}

