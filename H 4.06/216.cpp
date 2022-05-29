#include <algorithm>
#include <fstream>
using namespace std;

int n, m, k, a[150][150];
int b[150][150];

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, sum = 0, max = 0;
    in >> n;
    for(int i=0; i<n; ++i)
    {
        int value;
        in >> value;
        sum += value;
        max = std::max(max, value);
    }
    out << min(sum / 2, sum - max);
    return 0;
}