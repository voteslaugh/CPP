#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream out("output.txt");
    int n;
    input >> n;
    pair <int, int> dots;
    vector <int> vec(n);
    for (int i = 0; i < n; ++i)
        input >> vec[i];
    int min;
    if (vec[1] > vec[0])
        min = vec[1] - vec[0];
    else
        min = vec[0] - vec[1];
    dots = { 0,1 };
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            if (vec[i] > vec[j]) {
                if (vec[i] - vec[j] < min)
                {
                    min = vec[i] - vec[j];
                    dots = { j, i };
                }
            }
            else{
                if(vec[j]-vec[i]<min)
                {
                    min = vec[j] - vec[i];
                    dots = { i, j };
                }
            }

        }
    }
    out << min << endl << dots.first+1 << " " << dots.second+1;
    return 0;
}

