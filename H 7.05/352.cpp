#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

bool isCoprime(long a, long b) {
    for (long gcd = a; ; gcd = b, b = a % b, a = gcd)
        if (!b) return gcd == 1;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    long n, k=2, numer=1, denom;
    in >> n;
    denom = n - 1;
    n-=2;

    while(k<n)
    {   
        if(isCoprime(k, n))
        {
            numer = k;
            denom = n;
        }
        k++;
        n--;
    }
    out << numer << " " << denom;
    return 0;
}