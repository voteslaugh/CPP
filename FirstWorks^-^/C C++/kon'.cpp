#include <iostream>
using namespace std;



int main()
{
    string s;
    cin >> s;
    int count = 0;
    int y;
    y = s[1] - '0';
    int x;
    x = s[0] - 'a' + 1;
    short h[8][2] = { {1,2},{2,1},{-1,-2},{-2,-1}, {2,-1},{-1,2}, {1, -2} };
    for (int i = 0; i < 8; i++) {
        int x1 = x + h[i][0];
        int y1 = y + h[i][1];
        if (x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8) {
            count++;
        }
    }
