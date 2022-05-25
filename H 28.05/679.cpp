#include <fstream>
#include <cassert>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, n2, n3;
    in >> n;
    if(n % 3 == 0)
    {
        n2 = 0;
        n3 = n / 3;
    }
    else if(n % 3 == 1)
    {
        n2 = 2;
        n3 = (n - 4) / 3;
    }
    else
    {
        n2 = 1;
        n3 = (n - 2) / 3;
    }
    if(n2>0 && n3>0)
    {
        out << 2 << " " << n2 << " " << 3 << " " << n3;
    }
    else if(n2>0)
    {
        out << 2 << " " << n2;
    }
    else
    {
        out << 3 << " " << n3;
    }
    return 0;
}