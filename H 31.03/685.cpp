#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
int main()
{
    std::ifstream input("input.txt");
    std::ofstream out("output.txt");
    std::vector <int> a(3);
    std::vector <int> b(3);
    for (int i = 0; i < 3; ++i)
        input >> a[i];
    for (int i = 0; i < 3; ++i)
        input >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sum=0;
    for (int i = 0; i < 3; ++i)
        sum += a[i] * b[i];
    out << sum;
}
