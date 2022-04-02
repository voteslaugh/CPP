#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream out("output.txt");
    int n;
    input >> n;
    vector <float> power(n);
    vector <float> deg(n);
    vector <bool> check(n, 1);
    for(int i=0; i<n; ++i)
    {
        input >> power[i];
        input >> deg[i];
    }
    for(int i=0; i<power.size(); ++i)
    {
        if(cos(deg[i])<0)
        {
            deg.erase(deg.begin() + i);
            power.erase(power.begin() + i);
            check[i] = 0;
        }
    }

    for (int i = 0; i < power.size() - 1; ++i) {
        for (int j = i; j < power.size(); ++j) {
            if (pow(power[i], 2) + pow(power[j], 2) < pow(power[i], 2)) {
                deg.erase(deg.begin() + j);
                power.erase(power.begin() + j);
                check[j] = 0;
            }
        }
    }
    out << power.size() << endl;
    for (int i = 0; i < check.size(); ++i) {
        if (check[i] == 1)
            out << i+1 << " ";
    }
    return 0;
}
