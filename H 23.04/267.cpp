#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m;
	float lists;
	in >> lists >> n >> m;
	int i=0;
	while (lists>=0)
	{
		i++;
		lists -= ((float)1 / n + (float)1 / m);
	}

	out << i;

    return 0;
}
