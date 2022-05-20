#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void print(ofstream& out, const vector <long long> &vec)
{
    for (auto c : vec)
        out << c << " ";
    out << endl;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    char c;
    long long n, t = 1, r = 0;
    in >> c >> n;
    vector <long long> L, R;
    while(n>0)
    {
        r = n % 3;
        if (r == 2) {
            L.push_back(t);
            n += 3;
        }
        else if (r == 1)
            R.push_back(t);
        t *= 3;
        n /= 3;
    }
    if (c=='L')
    {
        out << "L:";
        print(out, L);
        out << "R:";
        print(out, R);
    }
    else
    {
        out << "L:";
        print(out, R);
        out << "R:";
        print(out, L);
    }
    return 0;
}