#include <iostream>
using namespace std;
int main(){
	int l, k, h;
	int min = 0;
	int max = 0;
	cin >> l >> k >> h;
	if (l % k == 0) {
		min = max = (l / k * h);
	}
	else {
		min = (l / k * h);
		max = (l / k * h + h);
	}
	cout << min << " " << max;
	return 0;
}
