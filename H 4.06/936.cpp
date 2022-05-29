#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int mX, mY, n;
    double r;
    in >> mX >> mY >> r >> n;
    vector <Point> p;
    for(int i=0; i<n; ++i)
    {
        int x, y;
        in >> x >> y;
        x -= mX;
        y -= mY;
        if (sqrt(x * x + y * y) <= r)
            p.push_back(Point{ x,y });
    }
    int ans = 0;
    for(Point p1: p)
    {
        int on = 0;
        int left = 0;
        int right = 0;
        for(Point p2: p)
        {
            int cp = p1.x * p2.y - p2.x * p1.y;
            if (cp < 0)
                left++;
            else if (cp > 0)
                right++;
            else
                on++;
        }
        ans = max({ ans, on + left, on + right });
    }
    out << ans;
    return 0;
}