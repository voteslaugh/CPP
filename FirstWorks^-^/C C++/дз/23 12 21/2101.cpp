#include <iostream>
#include <string>

std::pair<int, int> vector(int x1, int y1, int x2, int y2)
{
	return std::pair<int, int>(x2 - x1, y2 - y1);
}

std::pair<int, float> orthogonalVector(int x, int y)
{
	float a;
	a = -y / float(x);
	return std::pair<int, float>(1, a);
}



int main()
{
	int aX, aY;
	int bX, bY;
	int cX, cY;
	int nailX, nailY;
	std::cin >> aX >> aY >> bX >> bY >> cX >> cY >> nailX >> nailY;

}
