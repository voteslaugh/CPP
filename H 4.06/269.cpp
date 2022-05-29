#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    string a, b;
    in >> a >> b;
    int minLen = (int)a.size() + (int)b.size();
    for(int bPos=-(int)b.size(); bPos <= (int)a.size(); ++bPos)
    {
        int first = min(bPos, 0);
        int last = max(bPos + (int)b.size() - 1, (int)a.size() - 1);
        bool good = true;
        for(int i=first; i<=last; ++i)
        {
            int aVal;
            if (0 <= i && i < (int)a.size())
                aVal = a[i] - '0';
            else
                aVal = 1;
            int bVal;
            if (bPos <= i && i < bPos + (int)b.size())
                bVal = b[i - bPos] - '0';
            else
                bVal = 1;
            if(aVal + bVal > 3)
            {
                good = false;
                break;
            }
        }
        if(good)
        {
            int len = last - first + 1;
            if (len < minLen)
                minLen = len;
        }
    }
    out << minLen;
    return 0;
}