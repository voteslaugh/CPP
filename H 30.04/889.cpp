#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Hor
{
    int x;
    int y;
};

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int start, n;
    in >> start >> n;
    vector <Hor> h(n);
    for (int i = 0; i < n; ++i)
        in >> h[i].x >> h[i].y;
    sort(h.begin(), h.end(), [](const Hor& left, const Hor& right) 
        {
            return left.y > right.y;
        });
    int cur = start;
    for (Hor hor: h)
    {
        if (hor.x == cur)
            cur++;
        else if (hor.x + 1 == cur)
            cur--;
    }
    out << cur;
    return 0;
}

