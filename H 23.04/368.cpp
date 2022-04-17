#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void route(vector<vector<int>> &sum, const vector<vector<int>>& mas, vector<string> &res, const int& n)
{
    sum[0][0] = mas[0][0];
    for (int i = 1; i < n; i++)
    {
        sum[0][i] = mas[0][i] + sum[0][i - 1]; res[0][i] = 'l';
        sum[i][0] = mas[i][0] + sum[i - 1][0]; res[i][0] = 'u';
    }
    res[0][0] = 'i';
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            sum[i][j] = mas[i][j];
            if (sum[i - 1][j] < sum[i][j - 1])
            {
                sum[i][j] += sum[i - 1][j];
                res[i][j] = 'u';
            }
            else
            {
                sum[i][j] += sum[i][j - 1];
                res[i][j] = 'l';
            }
        }
    int x = n - 1, y = n - 1;
    bool isEnd = false;
    do
    {
        int X = x, Y = y;
        if (res[x][y] == 'u')   x--;
        else if (res[x][y] == 'l') y--;
        else if (res[x][y] == 'i') isEnd = true;
        res[X][Y] = '#';
    } while (!isEnd);
}

int main()
{

    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    vector<string> res(n, string(n,'-'));
    vector<vector<int> > mas(n, vector<int>(n, 0)), sum(n, vector<int>(n, 0 ));

    string s;
    for (int i = 0; i < n; ++i) {
        in >> s;
        for (int j = 0; j < s.size(); ++j) {
            mas[i][j] = s[j]-'0';
        }
    }

    route(sum, mas, res, n);
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (res[i][j] != '#')   out << '-';
            else    out << '#';
        out << endl;
    }
    return 0;
}
