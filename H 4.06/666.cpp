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
    int pos;
    in >> pos;
    for(int step=26; step>=1; --step)
    {
        int half = (1 << (step - 1)) - 1;
        if (pos == 1)
        {
            out << (char)('a' + step - 1);
            return 0;
        }
        else if (pos <= 1 + half)
            pos--;
        else
            pos -= 1 + half;
    }
    throw 1;
}