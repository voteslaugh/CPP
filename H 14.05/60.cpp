#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(const int &n)
{
    for (int i = 2; i <= n/i; ++i)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    int pos1=0, pos2=0;

    for(int i=1; ; ++i)
    {
        if (isPrime(i)) {
            pos1++;
            if (isPrime(pos1)) {
                pos2++;
                if (pos2 == n)
                {
                    out << i;
                    return 0;
                }
            }
        }

    }
}