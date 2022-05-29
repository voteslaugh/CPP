#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m, x, y, k=1, pos1 = 1, pos2=1;
    in >> n >> m >> y >> x;
    if(n==1 && n==m)
    {
        out << 1;
        return 0;
    }
    vector < vector<int>> vec(n, vector<int>(m));
    while(true)
    {
        while (pos2 < m) {
            ++pos2;
            ++k;
            if (pos1 == y && pos2 == x)
            {
                out << k;
                return 0;
            }
        }
        while(pos1 < n)
        {
            ++pos1;
            ++k;
            if (pos1 == y && pos2 == x)
            {
                out << k;
                return 0;
            }
        }
        while(pos2 != 1)
        {
            --pos2;
            ++k;
            if(pos1 == y && pos2 == x)
            {
                out << k;
                return 0;
            }
        }
        --n;
        --m;
        for (int i = 1; i < n; ++i) {
            pos1--;
            ++k;
            if (pos1 == y && pos2 == x)
            {
                out << k;
                return 0;
            }
        }

    }
}