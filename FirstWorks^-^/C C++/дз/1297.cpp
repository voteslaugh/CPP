#include <iostream>
#include <string>
#include<vector>
using namespace std;
string turn(string s)
{
    string news;
    for (int i = s.length() - 1; i >= 0; i--)
        news.push_back(s[i]);
    return news;
}
int main()
{
    string s; string news;
    getline(cin, s);
    vector <int> l;
    vector <string> counts;
    for (int i = 0; i < s.length(); i++)
    {
        int n = s.length();
        for (int j = 1; j <= s.length() - n + 1 && (s.length() - n + 1) <= (s.length() - i); j++)
        {
            news = s.substr(i, j);
            if (turn(news) == news && news.length() > 1)
            {
                l.push_back(news.length()); counts.push_back(news);
            }
            n--;
        }

    }
    int maxl = 0; string saves;
    for (int k = 0; k < l.size(); k++)
    {
        if (l[k] > maxl)
        {
            maxl = l[k]; saves = counts[k];
        }
    }
    cout << saves;
}