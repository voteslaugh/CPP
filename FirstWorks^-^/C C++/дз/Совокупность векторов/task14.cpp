/*Дана совокупность N векторов размерности M с целочисленными координатами   
S1, S2,…,SN  и векторY той же размерности M. Выбрать из совокупности те векторы, 
у которых координаты попарно – различны, и упорядочить их по возрастанию их скалярных произведений с вектором Y. 
В случае отсутствия таких векторов в совокупности выдать сообщение.*/
#include <iostream>
#include <fstream>
using namespace std;
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
int** read(int n, int m)
{
    ifstream fin("file.txt");
    int** arr = new int* [n+1];
    for (int i = 0; i < n + 1; i++) {
        i < n ? cout << "COORDINATES OF VECTOR NUMBER: " << i + 1 << endl << endl : cout << "COORDINATES OF Y VECTOR: ";
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            fin >> arr[i][j];
            cout << arr[i][j]<<" ";
        }
        cout << endl << endl;
    }
    return arr;
}

int* requireVectors(int n, int m,int &k, int** vector)
{
    int* y = new int[n];
    for (int i=1; i<n;i++)
    {
        for (int j = 0; j < m; j++) {
            if (vector[i][j] == vector[i - 1][j])
                break;
        }
        y[k] = i - 1;
        k++;
    }
    if (k == 0)
        cout << "Required vectors not found" << endl;
    else
        y[k + 1] = 111;
    return y;
}

int *mul(int** vector,int*y, int k, int n, int m)
{
    int x1 = 0;
    int* mul = new int[k];
    for(int i=0; i<k; i++)
    {
        mul[i] = 0;
        x1 = y[i];
        for (int j=0; j<m;j++)
        {
            mul[i] += vector[x1][j] * vector[n][j];
        }
    }
    return mul;
}

int main()//ввод с консоли: 5 3
{
    int n, m; //кол-во векторов и размерность
    cin >> n >> m;
    int** vector;
    vector = read(n, m);
    int k = 0;
    int* y;
    y = requireVectors(n, m,k, vector);
    int* mult = mul(vector, y, k, n, m);
    bubbleSort(mult, k);
    for (int i = 0; i < k; i++) {
        cout << mult[i] << endl;
    }
}

