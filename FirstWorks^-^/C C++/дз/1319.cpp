#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    


    a[0][x - 1] = 1;
    int m, n;
    int e = 1, value = 2, povt = 1, riad = 0, column = x - 2;
    while (e <= x - 1)
    {
        n = column, m = riad;
        for (int i = 0; i <= povt; i++)
        {
            a[m++][n++] = value;
            value++;
        }

        povt++; e++;
        column--;
    }
    riad = 1; column = 0, povt = x - 2;
    while (e > 1)
    {
        n = column, m = riad;
        for (int i = 0; i <= povt; i++)
        {
            a[m++][n++] = value;
            value++;
        }

        povt--; e--;
        riad++;
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}