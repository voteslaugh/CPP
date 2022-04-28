#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m;
    in >> n >> m;
    if (m==1)
    {
        out << n;
        return 0;
    }
    int s = 0;
    while (m % 2 != 0)
    {
        s += n / 2;
        n -= n / 2;
        m = (m + 1) / 2;
    }
    s += m / 2;
    out << s;
    return 0;
}

