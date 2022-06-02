#include <iostream>
#include <algorithm>
using namespace std;

int NOD(int x, int y) {
    if (x == 0 && y==0) return 0;
    if ((x == 0 || y == 0) && (x != 0 || y != 0)){
        if (x==0) return y;
        if (y==0) return x;
    }
    x = abs(x);
    y = abs(y);
    while (x != y) {
        if (x > y) {
            int temp = y;
            y = x;
            x = temp;
        }
        y = y - x;
    }
    return y;
}

int NOK(int x, int y) {
    return x * y / NOD(x, y);
}

void addition(int &x, int &y, int x1, int y1 ) {
    int temp = NOK(y, y1);
    x = (x * temp / y) + (x1 * temp / y1);
    y = temp;
}
void subtracting(int& x, int& y, int x1, int y1) {
    int temp = NOK(y, y1);
    x = (x * temp / y) - (x1 * temp / y1);
    y = temp;
}

void multiplication(int& x, int& y, int x1, int y1) {
    x = x * x1;
    y = y * y1;
}

void division(int& x, int& y, int x1, int y1) {
    x = x * y1;
    y = y * x1;
}   

void integer(int &x,int &y) {
    int temp = NOD(x, y);
    x = x / temp;
    y = y / temp;
    if (x%y==0) {
        cout <<"Only integer = " << x / y<<endl;
    }
    else if (y > x) {
        cout << "No integer, only fraction: "<<x<<"/"<<y<<endl;
    }
    else {
        temp = x / y;
        cout << "Integer and fraction: " << temp << " " << x - temp*y << "/" << y << endl;
    }
}

int main()
{
    int m, n, m1, n1;
    cin >> m >> n>>m1>>n1;
    subtracting(m, n, m1, n1);
    integer(m, n);
}

