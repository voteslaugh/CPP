#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
int main()
{
    std::ifstream input("input.txt");
    std::ofstream out("output.txt");
    std::vector <int> vec(3);

    for (int i = 0; i < 3; ++i)
        input >> vec[i];
    sort(vec.begin(), vec.end());
    vec[0] + vec[1] == vec[2] ? out << "YES" : out << "NO";
    
}
