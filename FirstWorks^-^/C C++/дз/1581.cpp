#include <iostream>
using namespace std;

int main()
{
    while (true) {
        int n;
        cin >> n;
        if (n == 1) {
            int x;
            cin >> x;
            cout << 1 << " " << x;
            break;
        }
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr[i] = x;
        }
        int times = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                times++;
            }
            else {
                cout << times << " " << arr[i - 1] << " ";
                times = 1;
            }
            if (i == n - 1) {
                cout << times << " " << arr[i];
            }
        }
        break;
    }
    return 0;
}
