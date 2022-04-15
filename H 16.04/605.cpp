#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

void DartsThrow(int remPoints, int remThrow, string s, vector <string>& res)
{
    if(remPoints == 0)
    {
        res.push_back(s.substr(1));
        return;
    }

    for (int i = 1; i <= 20; ++i) {
        if (i<remPoints && remThrow>1)
        {
            DartsThrow(remPoints - i, remThrow - 1, s + " " + to_string(i), res);
        }
    }
    for (int i=1; i<=20; ++i)
    {
        if ((2*i<=remPoints && remThrow == 1) || (2*i <= remPoints && remThrow > 1))
        {
            DartsThrow(remPoints - 2*i, remThrow - 1,  s + " D" + to_string(i), res);
        }
    }
    for (int i = 1; i <= 20; ++i)
    {
        if (3 * i < remPoints && remThrow>1)
        {
            DartsThrow(remPoints - 3 * i, remThrow - 1, s + " T" + to_string(i), res);
        }
    }
    if (25 < remPoints && remThrow>1)
    {
        DartsThrow(remPoints - 25, remThrow - 1, s + " 25", res);
    }

    if ((50 <= remPoints && remThrow == 1) || (50 <= remPoints && remThrow > 1))
    {
        DartsThrow(remPoints - 50, remThrow - 1, s + " Bull" , res);
    }

   
}

int main()
{
    ifstream input("input.txt");
    ofstream out("output.txt");
    int n;
    input >> n;
    vector <string> res;
    DartsThrow(n, 3, "", res);
    out << (int)res.size() << endl;
    for (auto c: res)
    {
        out << c << endl;
    }
    return 0;
}

