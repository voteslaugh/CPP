#include <fstream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, vBegin, vEnd;
    in >> n;
    vector <vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            in >> a[i][j];
    in >> vBegin >> vEnd;
    vBegin--;
    vEnd--;
    const int UNDEF = -1;
    vector <int> len(n, UNDEF);
    queue <int> q;
    q.push(vBegin);
    len[vBegin] = 0;
    while(true)
    {
        if(q.empty())
        {
            out << -1;
            return 0;
        }
        int cur = q.front();
        q.pop();
        if (cur==vEnd)
        {
            out << len[vEnd];
            return 0;
        }
        for(int next=0; next<n; ++next)
            if(len[next] == UNDEF && a[cur][next] == 1)
            {
                q.push(next);
                len[next] = len[cur] + 1;
            }
    }
    return 0;
}