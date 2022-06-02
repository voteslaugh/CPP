#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n1, c1, n2, t, c2, n3, k, time = 0, min, sec, conv;
    cin >> n1 >> c1 >> n2 >> t >> c2 >> n3 >> k;
    for (int i = 0; i < k; i++) {
        scanf("%d:%d", &min, &sec);
        conv = min * 60 + sec;
        time += conv > 6 ? (conv + 59) / 60 : 0;
    }
    cout << "Basic:     " << n1 + time * c1 << endl;
    cout << "Combined:  " << n2 + max(time - t, 0) * c2 << endl;;
    cout << "Unlimited: " << n3;
}