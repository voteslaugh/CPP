#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    long long n;
    in >> n;
    vector <short int> vec(n);
    for (int i = 0; i < n; ++i)
        in >> vec[i];
    sort(vec.begin(), vec.end());
    int mul = 1;
    int i = 0;
    for (int j = n-1; j >= 0; --j) {
        if (vec[j]!=0)
        {
            ++i;
           mul *= vec[j];
        }
        if (i == 3)break;
    }

    out << mul;
}
