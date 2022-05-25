#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    size_t n, k, answ;
    string word;
    in >> n >> k >> word;
    if(k == n)
    {
        answ = n;
        for(int i=2; i<n; ++i)
        {
            n % i == 0 ? answ += n / i + 1: answ += n / i + 2;
        }
        out << answ;
        return 0;
    }
    answ = n;
    for(int i=1; i<k+1; ++i)
    {
        answ += tgamma(i + 1 + 1);
    }
    for(int count=k+2; count < n; ++count)
    {
        for (int i = 0; i < n - count + 1; ++i) {
            for (int j = i; j < i + count / 2; ++j)
            {
                size_t temp = 0;
                if (word[j] != word[count - j - 1]) temp++;
                if (temp > k) break;    
                if (j >= count / 2 - 1) {
                    answ++;
                    break;
                }
            }
        }
    }
    out << answ;
    return 0;
}