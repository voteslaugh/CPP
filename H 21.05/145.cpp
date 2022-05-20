#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define PB push_back
#define ll long long
using namespace std;
typedef vector<int> lll;


istream& operator >>(istream& stream, lll& a) {
	string s; stream >> s;
	for (int i = s.size() - 1; i >= 0; --i)a.PB(s[i] - '0');
	return stream;
}
ostream& operator <<(ostream& stream, lll a) {
	for (int i = a.size() - 1; i >= 0; --i)stream << a[i];
	return stream;
}

bool operator >(lll a, lll b) {
	if (a.size() > b.size())return true;
	if (a.size() < b.size())return false;
	for (int i = a.size() - 1; i >= 0; --i) {
		if (a[i] > b[i])return true;
		if (a[i] < b[i])return false;
	}
	return false;
}
lll operator +(lll a, lll b) {
	lll c; int i, r = 0;
	for (i = 0; i < a.size() || i < b.size(); ++i) {
		if (i < a.size())r += a[i];
		if (i < b.size())r += b[i];
		c.PB(r % 10); r /= 10;
	}
	if (r)c.PB(r);
	return c;
}
lll operator -(lll a, lll b) {
	lll c; int i, r = 0;
	for (i = 0; i < a.size(); ++i) {
		r += a[i];
		if (i < b.size())r -= b[i];
		if (r < 0) { c.PB(r + 10); r = -1; }
		else { c.PB(r % 10); r = 0; }
	}
	while (c.size() > 1 && c.back() == 0)c.pop_back();
	return c;
}
lll operator *(lll a, ll b) {
	lll c; int i; ll r = 0;
	if (b == 0) { c.PB(0); return c; }
	for (i = 0; i < a.size(); ++i) {
		r += a[i] * b;
		c.PB(r % 10); r /= 10;
	}
	while (r) { c.PB(r % 10); r /= 10; }
	return c;
}
lll operator /(lll a, ll b) {
	lll c; int i; ll r = 0, t;
	for (i = a.size() - 1; i >= 0; --i) {
		r = r * 10 + a[i]; t = r / b;
		c.insert(c.begin(), t); r -= t * b;
	}
	while (c.size() > 1 && c[c.size() - 1] == 0)
		c.resize(c.size() - 1);
	return c;
}
ll operator % (lll a, ll b) {
	lll c; int i; ll r = 0, t;
	for (i = a.size() - 1; i >= 0; --i) {
		r = r * 10 + a[i]; t = r / b; r -= t * b;
	}
	while (c.size() > 1 && c[c.size() - 1] == 0) c.resize(c.size() - 1);
	return r;
}


int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
	lll a;
	ll b;
	in >> a >> b;
	out << a / b;
    return 0;
}