#include <iostream>
using namespace std;
int main() {
    unsigned int n;
    cin >> n;
    unsigned int max = n;
    for (unsigned int i = 2; i * i <= max; )
        if (n % i == 0) cout << i << ((n /= i) == 1 ? "" : "*");
        else ++i;
    if (n > 1) cout << n;
    return 0;
}