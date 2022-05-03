#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    string N;
    long K;
    in >> N >> K;
    int i = 0;
    long answ = 0;
    while (i < N.length()) {
        while (answ < K)
            answ = answ * 10 + N[i++] - '0';
        answ = answ % K;
    }
    out << answ;
    return 0;
}