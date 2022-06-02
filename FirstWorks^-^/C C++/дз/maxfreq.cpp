#include <iostream>
using namespace std;

int main()
{
    int n, a, count = 0, max = 0, p;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[i] = a;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max) {
            max = count;
            count = 0;
            p = arr[i];
        }
        else
            count = 0;
    }
    cout << p;
    return 0;
}
