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
    int b = a % 3;
    a /= 3;
    switch(a)
    {
    case 0:
        out << "Winter";
        break;
    case 1:
        out << "Spring";
        break;
    case 2:
        out << "Summer";
        break;
    case 3:
        out << "Autumn";
        break;
    case 4:
        b == 0 ? out << "Winter" : out << "Error";
        break;
    default:
        out << "Error";
        break;
    }

}
