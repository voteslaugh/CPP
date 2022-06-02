#include <iostream>
using namespace std;
int main() {
    int a, b, c, num;
    cin >> num;
    a = num / 100;
    b = num / 10 % 10;
    c = num % 10;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
