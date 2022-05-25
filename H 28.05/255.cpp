#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
	int n, i = 1;
	in >> n;
	for (int j = 2; i <= sqrt(n); ++j)
	{
		if (n % j == 0)
		{
			for (i <= sqrt(n); ++i;)
			{
				if (n % i == 0)
				{
					break;
				}
			}
			out << n / i << " " << n - (n / i);
			return 0;
		}
	}
	out << 1 << " " << n - 1;
    return 0;
}