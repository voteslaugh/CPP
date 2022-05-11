#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    unsigned int n, m;
    in >> n >> m;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
        in >> vec[i];
    sort(vec.begin(), vec.end());
    for( int i=0; i<n-1;)
    {
        if (vec[i] == vec[i + 1])
            ++i;
        else if((vec[i+1]-vec[i])*(i+1)>m)
        {
            out << vec[0]+(vec[i + 1] - vec[i])/(i+1)+m/(i+1);
            return 0;
        }
        else if((vec[i + 1] - vec[i]) * (i + 1) <= m)
        {
            m -= (vec[i + 1] - vec[i]) * (i + 1);
            for (int j = 0; j <= i; ++j)
                vec[j] = vec[i + 1];
            ++i;
        }
    }

    out << vec[0]+m/n;
    return 0;
}