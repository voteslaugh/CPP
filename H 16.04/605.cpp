#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

void addWays(int remPoints, int remMoves, string s, vector <string>& res)
{
    if(remPoints == 0)
    {
        res.push_back(s.substr(1));
        return;
    }

    for (int i = 1; i <= 20; ++i) {
        if (i<remPoints && remMoves>1)
        {
            addWays(remPoints - i, remMoves - 1, s + " " + to_string(i), res);
        }
    }
    for (int i=1; i<=20; ++i)
    {
        if ((2*i<=remPoints && remMoves == 1) || (2*i <= remPoints && remMoves > 1))
        {
            addWays(remPoints - 2*i, remMoves - 1,  s + " D" + to_string(i), res);
        }
    }
    for (int i = 1; i <= 20; ++i)
    {
        if (3 * i < remPoints && remMoves>1)
        {
            addWays(remPoints - 3 * i, remMoves - 1, s + " T" + to_string(i), res);
        }
    }
    if (25 < remPoints && remMoves>1)
    {
        addWays(remPoints - 25, remMoves - 1, s + " 25", res);
    }

    if ((50 <= remPoints && remMoves == 1) || (50 <= remPoints && remMoves > 1))
    {
        addWays(remPoints - 50, remMoves - 1, s + " Bull" , res);
    }

   
}

int main()
{
    ifstream input("input.txt");
    ofstream out("output.txt");
    int n;
    input >> n;
    vector <string> res;
    addWays(n, 3, "", res);
    out << (int)res.size() << endl;
    for (auto c: res)
    {
        out << c << endl;
    }
    return 0;
}

