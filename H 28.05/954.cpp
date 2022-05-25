#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int height;
    in >> height;
    vector<int>count(height + 1, 0);
    count[0] = 1;
    const int MOD = 1000 * 1000;
    for(int h=1; h<= height; ++h)
    {
        if (h >= 10)
            count[h] += count[h - 10];
        if (h >= 11)
            count[h] += count[h - 11];
        if (h >= 12)
            count[h] += count[h - 12];
        count[h] %= MOD;
    }
    out << count[height] * 2 % MOD;
    return 0;
}