#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
int main()
{
    std::ifstream input("input.txt");
    std::ofstream out("output.txt");
    int a;
    input >> a;
    std::vector <int> vec(a);
    for (int i = a-1; i >= 0; --i)
        input >> vec[i];
    for (auto c : vec)
        out << c<<" ";
    
}
