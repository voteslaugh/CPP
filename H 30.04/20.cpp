#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    vector <int> vec(n);
    for (int i = 0; i < n; ++i)
        in >> vec[i];
    int cur = vec[0];
    int prev = vec[0];
    int prevprev = vec[0];
    int len = 0, maxlen = 0;
    for(int i=1; i<n; ++i)
    {
        prevprev = prev;
        prev = cur;
        cur = vec[i];
        if ((prev > cur && prev > prevprev) || (prev < cur && prev < prevprev)) len++;
        else if (prev != cur) len = 2;
        else len = 1;
        maxlen = max(maxlen, len);
    }
    out << maxlen;
    return 0;
}

