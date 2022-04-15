#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream out("output.txt");
    int n;
    input >> n;
    vector<int>R3(3, 0);
    vector<int>R2(2, 0);
    for(int i=0; i<n;++i)
    {
        char s;
        input >> s;
        int x;
        input >> x;
        if (s == 'X') R3[0] += x;
        if (s == 'Y') R3[1] += x;
        if (s == 'Z') R3[2] += x;
    }
    while (R3[1] * R3[2] > 0)
    {
        if (R3[1] > 0 && R3[2] > 0) {
            R2[1]+=2;
            R3[1]--;
            R3[2]--;
        }
        else {
            R2[1] -= 2;
            R3[1]++;
            R3[2]++;
        }
    }
    while ((abs(R3[0]) > 0 && abs(R3[1]) > 1) || (abs(R3[0]) > 0 && abs(R3[2]) > 1))
    {
        if (R3[0] > 0) {
            R3[0]--;
            if(R3[1]<1)
            {
                R3[1] += 2;
                R2[1] -= 2;
            }
            else if (R3[2] > 1)
            {
                R3[2] -= 2;
                R2[1] += 2;
            }
        }
        if (R3[0] < 0) {
            R3[0]++;
            if (R3[1] > 1)
            {
                R3[1] -= 2;
                R2[1] += 2;
            }
            else if (R3[2] < 1)
            {
                R3[2] += 2;
                R2[1] -= 2;
            }
        }
    }
    R2[0] = R3[0];
    out << abs(R2[0]) + abs(R2[1]);
    return 0;
}

