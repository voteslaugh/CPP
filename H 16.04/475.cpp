#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream out("output.txt");
    vector <int> vec;
    while(!input.eof())
    {
        int a;
        input >> a;
        vec.push_back(a);
    }
    if (vec.size()==2)
        out << "Yes";
    else {
        sort(vec.begin(), vec.end());
        int d = vec[1] - vec[0];
        for(int i=1; i<vec.size()-1; ++i)
        {
            if (vec[i + 1] - vec[i] != d) {
                out << "No";
                return 0;
            }
        }
        out << "Yes";
    }
    return 0;
}

