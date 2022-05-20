#include <fstream>
#include <cmath>
using namespace std;
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    long long maxPow = pow(3, n / 3);
    if (n % 3 == 1)
        maxPow = maxPow * 4 / 3;
    if (n % 3 == 2)
        maxPow = maxPow * 2;
 
    out << maxPow;
}