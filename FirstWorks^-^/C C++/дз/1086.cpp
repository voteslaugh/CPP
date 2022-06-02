#include<iostream>
#include<vector>
using namespace std;

int main() {
	int k;
	int n;
	cin >> k;
	vector <int> v;
	bool f=true;
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	for (int i = 9; i < 100000; i++) {
		f=true;
		for (int j=3; j*j<=i;j+=2) {
			if(i%j==0){
			f=false;
			break;
			}
			if (f) v.push_back(i);
		}
	}
	vector <int> numbs;
	for (int i = 0; i < k; i++) {
		cin >> n;
		numbs.push_back(n);
	}
	for (auto c : numbs) {
		cout << v[c-1] << endl;
	}
}