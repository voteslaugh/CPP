#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

void solution(vector <int> &vect, int &t, int &m)
{
	for (int i = 0; i < m; ++i) {
		int stn1 = vect[t];
		int stn2 = vect[(t + 1 + vect.size()) % vect.size()];
		int stn3 = vect[(t + 2 + vect.size()) % vect.size()];
		vect[t] = 0;
		vect[(t + 1 + vect.size()) % vect.size()] = 0;
		vect[(t + 2 + vect.size()) % vect.size()] = 0;
		int ind = 0;
		if (stn1 == 1 || (stn1 == 2 && (stn2 == 1 || stn3 == 1)) || ((stn1 == 3 && (stn2 + stn3 == 3)))) {
			for (int j = 0; j < vect.size(); ++j) {
				if (vect[j] > vect[ind]) {
					ind = j;
				}
			}
		}
		else {
			for (int j = 0; j < vect.size(); ++j) {
				if (vect[j] < stn1 && vect[j] > vect[ind]) {
					ind = j;
				}
			}
		}
		while (t != ind) {
			vect[(t + 2 + vect.size()) % vect.size()] = vect[(t - 1 + vect.size()) % vect.size()];
			t = (t - 1 + vect.size()) % vect.size();
		}
		vect[ind] = stn1;
		vect[(ind + 1 + vect.size()) % vect.size()] = stn2;
		vect[(ind + 2 + vect.size()) % vect.size()] = stn3;
		t = (t + 3 + vect.size()) % vect.size();
	}
}

void main()
{ 
	int n; //кол-во камней
	cin >> n;
	vector <int> vect(n);
	for (int i = 0; i < n; ++i) {
		cin >> vect[i];
	}
	int m;
	cin >> m;
    int t = 0;
	solution(vect, t, m);
	for (int i = 0; i < n; ++i) {
		cout << vect[i] << " ";
	}
} 