#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    unsigned short int n, m;
    unsigned int answ;
    in >> n >> m;

    if (m == 0)
        out << n * tgamma(n + 1);
    else
        out << tgamma(n + 1) / (tgamma(m + 1) * tgamma(n - m)) + tgamma(n + 1) / (tgamma(n + 1) * tgamma(n - m));
    return 0;
}