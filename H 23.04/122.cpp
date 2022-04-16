#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
    int n;
    in >> n;
    vector<int> vec(n);
    vector<int> len(n, 0);
    for (int i = 0; i < n; ++i)
        in >> vec[i];
    int maxlen = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (vec[j] < vec[i])
                if (len[j] > len[i]) len[i] = len[j];
        }
        len[i]++;
        if (maxlen < len[i])
            maxlen = len[i];
    }
    out << maxlen;
    return 0;
}