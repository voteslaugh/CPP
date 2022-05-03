#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    short int n;
    in >> n;
    float dol, eu, prevdol, preveu, mon;
    mon = 100;
    in >> prevdol >> preveu;
    for(int i=0; i<n-1; ++i)
    {
        in >> dol >> eu;
        if(prevdol < dol || preveu < eu)
        {
            mon = max(((mon - prevdol*(mon / prevdol)) + (mon / prevdol)*(dol)), ((mon - preveu*(mon / preveu)) + (mon / preveu) * (eu)));
        }
        prevdol = dol;
        preveu = eu;
    }
    out << std::fixed << std::setprecision(2) << mon << std::endl;
    return 0;
}