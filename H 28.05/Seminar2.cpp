#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

template<typename T>
T sum_all(const vector <T> &vec)
{
    T sum = vec[0];
    for (int i = 1; i < vec.size(); ++i)
        sum += vec[i];
    return sum;
}
string sum_all(const vector<char> &vec)
{
    string sum ="";
    for (int i = 0; i < vec.size(); ++i)
        sum += vec[i];
    return sum;
}
template <typename T>
T sum_all(T a)
{
    return a;
}

int main()
{
    vector<int> vec = { 1 , 2, 3 };
    vector <float> vec1 = { 1, 2, 3 };
    vector <string> vec2 = { "ab", "cd" };
    vector<char> vec3 = { 'a', 'b', 'c' };
    cout << sum_all(vec) << endl << sum_all(vec1) << endl << sum_all(vec2) << endl << sum_all(vec3) << endl<< sum_all(5.5);
}