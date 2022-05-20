#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ifstream in("INPUT.TXT");
	ofstream out("OUTPUT.TXT");
	int n, m, k;
	in >> n >> m >> k;
	int i, j, l, i1, j1;
	vector<vector<int>>vec(n, vector<int>(m, 0));
	for (int l = 0; l < k; ++l) {
		in >> i >> j;
		vec[i][j] = -1;
	}
	int coun = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; k < m; ++k) {
			if ((vec[i-1][j]==coun || vec[i][j-1]==coun || vec[i+1][j]==coun|| vec[i][j+1]==coun) && vec[i][j]==0) {
				vec[i][j] = coun;
			}
			else if (vec[i][j] == 0) {
				vec[i][j] = ++coun;

			}
		}
	}
	out << coun << endl;
	
}