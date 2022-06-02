#include <iostream>

using namespace std;

int main()
{
    int n, x, y, x1, y1;
    int i = 0;
    cin >> n >> x >> y;
    if (x + 1 <= n) {
        i++;
        if (y + 1 <= n) i++;
        if (y - 1 >= n) i++;
    }
    if (x - 1 >= 1){
        if (y + 1 <= n) i++;
        if (y - 1 >= n) i++;
        i++;
    if (y + 1 <= n)
        i++;
    if (y - 1 >= 1)
        i++;
    cout << "King: " << i << endl;






    i = 0;
    int knight_arr[8][2]{ x + 1, y + 2, x + 2, y + 1, x + 2, y - 1, x + 1, y - 2, x - 1, y - 2, x - 2, y - 1, x - 2, y + 1, x - 1, y + 2 };
    for (int j = 0; j < 8; j++) {
        x1 = knight_arr[j][0];
        y1 = knight_arr[j][1];
        if (x1 >= 1 && y1 >= 1 && x1 <= n && y1 <= n)
        {
            i++;
        }
    }
    cout << "Knight: " << i << endl;








    i = 0;
    x1 = x + 1;
    y1 = y + 1;
    while (x1 <= n && y1 <= n) {
        i++;
        x1++;
        y1++;
    }
    x1 = x - 1;
    y1 = y - 1;
    while (x1 >= 1 && y1 >= 1) {
        i++;
        x1--;
        y1--;
    }
    x1 = x + 1;
    y1 = y - 1;
    while (x1 <= n && y1 >= 1) {
        i++;
        x1++;
        y1--;
    }
    x1 = x - 1;
    y1 = y + 1;
    while (x1 >= 1 && y1 <= n) {
        i++;
        x1--;
        y1++;
    }
    cout << "Bishop: " << i << endl;







    int rook = 0;
    x1 = x;
    y1 = y;
    x1++;
    while (x1 <= n) {
        rook++;
        x1++;
    }
    x1 = x;
    x1--;
    while (x1 >= 1) {
        rook++;
        x1--;
    }
    y1++;
    while (y1 <= n) {
        rook++;
        y1++;
    }
    y1 = y;
    y1--;
    while (y1 >= 1) {
        rook++;
        y1--;
    }
    cout << "Rook: " << rook << endl;








    i += rook;
    cout << "Queen: " << i << endl;
}