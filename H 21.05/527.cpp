#include <fstream>
#include <algorithm>
#include <cassert> 
using namespace std;

bool EuclidAlgo(long long& a, long long& b, const long long & c, const long long & d)
{
    if (a == c && b == d)
        return true;
    while (b != 0) {
        if (b > a) {
            std::swap(a, b);
            if (a == c && b == d)
                return true;
        }
        if (b > 0) {
            long long nSub = a / b;
            long long oldA = a;
            a -= nSub * b;
            long long newA = a;
            if (b == d && newA <= c && c <= oldA && (oldA - c) % b == 0)
                return true;
        }
    }
    return false;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    long long a, b, c, d;
    in >> t;
    for(int i=0; i<t; ++i)
    {
        in >> a >> b >> c >> d;
        if (EuclidAlgo(a, b, c, d))
            out << "YES" << endl;
        else
            out << "NO"<<endl;
    }
    return 0;
}