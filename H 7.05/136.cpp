#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    unsigned short int n;
    in >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    long long answ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> vec[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && vec[i][k] != -1 && vec[k][j] != -1) {
                    if (vec[i][j] == -1) {
                        vec[i][j] = vec[i][k] + vec[k][j];
                    }
                    else
                    {
                        vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vec[i][j] > answ) answ = vec[i][j];
        }
    }
    out << answ << endl;
    return 0;
}