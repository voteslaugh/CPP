﻿#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    if(n%2 == 1)
    {
        out << "0";
        return 0;
    }
    vector <double> count(1 + n);
    count[0] = 1;
    for(int i=2; i<=n; i+=2)
    {
        count[i] = count[i - 2]*3;
        for (int j = i - 4; j >= 0; j -= 2)
            count[i] += count[j] * 2;
    }
    out << count[n];
    return 0;
}