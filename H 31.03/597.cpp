#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
int main()
{
    std::ifstream input("input.txt");
    std::ofstream out("output.txt");
    int size, a, b;
    input >> size >> a >> b;
    a + b <= size ? out << "YES" : out << "NO";
}
