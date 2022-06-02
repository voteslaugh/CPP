// ConCPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main() {
	int num, a, b, c, d, e, f;
	cin >> num;
	a = num / 100000;
	b = num / 10000 % 10;
	c = num / 1000 % 10;
	d = num / 100 % 10;
	e = num / 10 % 10;
	f = num % 10;
	if ((f + 1 == 10) && (a + b + c) == (d + e + 1)) {
		cout << "Yes" << endl;
	}
	if (((f + 1 < 10)&&(a+b+c==d+e+f+1))|| ((f + 1 < 10) && (a + b + c == d + e + f - 1))){
		cout << "Yes" << endl;

}
	else

		cout << "No" << endl;
	
	
	
	
	return 0;
}