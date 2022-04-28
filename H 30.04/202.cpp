#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    string str, samp;
    in >> str >> samp;
    int i = -1;
    while (samp.size()<=str.size())
    {
        ++i;
        if (str.substr(0, samp.size()) == samp)
            out << i << " ";
        str.erase(0, 1);
    }
    return 0;
}

