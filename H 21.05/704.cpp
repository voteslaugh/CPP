#include <fstream>
#include <vector>
using namespace std;

float mlt(float x0, float y0, float x1, float y1) 
{
    return x0 * y1 - x1 * y0;
}
float scal(float x0, float y0,float x1, float y1)
{
    return x0 * x1 + y0 * y1;
}

int sign(float &a)
{
    return (a > 0) - (a < 0);
}

void main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int sz, n;
    in >> sz >> n;
    vector<int> vec(n * 2);
    for (int i = 0; i < n*2-1; ++i) {
        in >> vec[i];
    }
    bool flag = false;
    float x0 = sz / 2;
    float y0 = sz / 2;
    for(int i=0; i<n; ++i)
    {
        float x1 = vec[2 * i];
        float y1 = vec[2 * i + 1];
        int c[3] = { 0,0,0 };
        int c0[3] = { 0,0,0 };
        for(int j=0; j<n; ++j)
        {
            float x2 = vec[2 * j], y2 = vec[2 * j + 1];
            float vect = mlt(x1 - x0, y1 - y0, x2 - x0, y2 - y0);
            c[sign(vect)] += 1;
            if (vect == 0)
            {
                float sc = scal(x1 - x0, y1 - y0, x2 - x0, y2 - y0);
                c0[sign(sc)] += 1;
            }
        }
        if (c[2] + c0[1] == n || c[1] + c0[1] == n)
            flag = true;
    }
    flag ? out << "YES" : out << "NO";
}
