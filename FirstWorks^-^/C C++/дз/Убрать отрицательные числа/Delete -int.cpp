#include <fstream>
#include <iostream>
using namespace std; //Удалить из массива все отрицательные значения, а оставшиеся уплотнить (сдвинуть )
                    //с сохранением исходного порядка к началу массива. 
int elementsnumber()
{
    ifstream file("file.txt");
    int count = 0;
    int x;
    while (file >> x) count++;
    return count;
}

void massive(int arr[], int count)
{
    ifstream file("file.txt");
    int x;
    for (int i = 0; i < count; i++)
    {
        file >> x;
        arr[i] = x;
    }
}

void massivechange(int arr[], int &count)
{
    for (int i=0; i<count; i++)
    {
        if (arr[i]<0)
        {
            for (int j=i; j<count; j++)
                arr[j] = arr[j + 1];
            count--;
        }
    }
}

int main()
{
    int count = elementsnumber();
    int* numbers = new int[count];
    massive(numbers, count);
    massivechange(numbers, count);
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << endl;
    }
}
