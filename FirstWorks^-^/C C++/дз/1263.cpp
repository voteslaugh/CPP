#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a;
    double b;
    cin >> a >> b;
    int c;
    int* arr = new int[a];
    for (int i = 0; i < a; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < b; i++) {
        cin >> c;
        arr[c - 1]++;
    }
    float answ;
    for (int i = 0; i < a; i++) {
        answ = arr[i] * 100 / b;
        // cout << setprecision(4) << answ<< "%"<< endl;
        printf("%.2f%%\n", answ);

    }

    return 0;
}
