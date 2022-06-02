#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool oneline(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if ((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3) == 0) {
		return true;
	}
}

long double fact(int N)
{
	if (N < 0)
		return 0; 
	if (N == 0) 
		return 1; 
	else 
		return N * fact(N - 1); 
}

int main()
{

	int n, x1, y1, x2, y2, x3, y3;
	cin >> n;
	vector <int> x;
	vector <int> y;
	vector <int> sortx;
	vector <int> sorty;
	for (int i = 0; i < n; i++) {
		cin >> x1;
		cin >> y1;
		if (i % 2 == 0) {
			x.push_back(x1);
			sortx.push_back(x1);
		}
		else {
			y.push_back(y1);
			sorty.push_back(y1);
		}
	}
	
	sort(sorty.begin(), sorty.end());
	sort(sortx.begin(), sortx.end());
	float medx;
	float medy;
	medx = ((float)sortx[size(sortx) / 2 - 1] + sortx[(float)size(sortx) / 2 + 1]) / 2;
	medy = ((float)sorty[size(sorty) / 2 - 1] + sorty[(float)size(sorty) / 2 + 1]) / 2;

	/////////////////////////////////////////////////////////////////////
	
	sorty.clear();
	sortx.clear();
	bool line = false;
	for (int i = 0; i < 3*size(x); i++) {
		x.push_back(x[i]);
		y.push_back(y[i]);
	}
	for (int i = 0; i < fact(size(x)); i++) {
		if (i < size(x) - 1) {
			x1 = x[i];
			y1 = y[i];
			x2 = x[i + 1];
			y2 = y[i + 1];
		}
		if (i < 2*size(x) - 2) {
			x1 = x[i];
			y1 = y[i];
			x2 = x[i + 2];
			y2 = y[i + 2];
		}
		line = oneline(x1, y1, x2, y2, medx, medy);
		if (line) {
			break;
			cout << i;
		}
	}
}
