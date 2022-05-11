#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int main() { 
	int a[50] = { 3,4, 5, 6, 9, 10, 11, 12, 13,16, 17, 18, 19, 20, 23,24, 25, 26, 27, 30, 31, 32, 33, 34, 37, 38, 39, 40, 41, 44 , 45, 46, 47, 48, 51, 52, 54, 55, 58, 59, 60, 61, 62, 65, 67, 68, 69, 72, 73, 74 };
	ifstream in("input.txt");
	ofstream out("output.txt");
	unsigned int k;
	in >> k; 
	out << a[k - 1]; 
}