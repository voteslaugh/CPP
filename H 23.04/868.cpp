#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m;
    in >> n >> m;
    vector <vector<int>>vec(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            in >> vec[i][j];
    for (int i = 0; i < m - 1; ++i)
    {
        for (int k = 0; k < n; ++k) {
            if (vec[k][i] < vec[k][i + 1])
            {
                for (int j = 0; j < n; j++) {
                    int temp = vec[j][i];
                    vec[j][i] = vec[j][i + 1];
                    vec[j][i + 1] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int k = 0; k < m; ++k) {
            if (vec[i][k] < vec[i + 1][k])
            {
                for (int j = 0; j < m; j++) {
                    int temp = vec[i][j];
                    vec[i][j] = vec[i + 1][j];
                    vec[i + 1][j] = temp;
                }
            }
        }
    }

    out << vec[n - 1][m - 1];
}
