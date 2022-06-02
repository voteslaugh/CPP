#include <iostream>
#include <cmath>
#define PI 3.14159265 
using namespace std;
void swap1(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swap(double* xp, double* yp)
{
	double temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(double arr[], int arr1[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swap1(&arr1[j], &arr1[j + 1]);
			}
				
}
int number;
int main()
{
	int n, x, y, value;
	cin >> n;
	int** dots = new int* [n];
	for (int i = 0; i < n; i++)
	{
		dots[i] = new int[2];
		cin >> x >> y;
		if (i == 0) value = sqrt(x * x + y * y);
		dots[i][0] = x;
		dots[i][1] = y;
		if (sqrt(x * x + y * y) < value)
		{
			value = sqrt(x * x + y * y);
			number = i;
		}
	}
	//cout << number << endl;
	double* degrees = new double[n-1];
	int* numbers = new int[n - 1];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (i != number) {
			degrees[i] = acos((dots[i][0] - dots[number][0])/(sqrt(pow(dots[i][0] - dots[number][0], 2)+pow(dots[i][1] - dots[number][1], 2))));
			numbers[j] = i;
			j++;
		}
	}
	bubbleSort(degrees, numbers, n-1);
	cout << number+1 << " " << numbers[(n-1) / 2+1]+1 << endl;
}

	