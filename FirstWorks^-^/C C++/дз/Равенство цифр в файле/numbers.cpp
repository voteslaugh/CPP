#include <iostream>
#include <fstream>
using namespace std;                 //Все ли элементы последовательности равны между собой? 

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

bool equal(int arr[], int count)
{
    for (int i=1; i<count; i++)
    {
        if (arr[i - 1] == arr[i]) continue;
        else return false;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int count = elementsnumber();
    if(count==0)
    {
        cout << "Файл пуст" << endl;
        return 0;
    }
    int* arr = new int[count];

    massive(arr, count);

    if (equal(arr, count) == true) cout << "Все цифры между собой равны"<<endl;
    else cout << "Цифры не равны между собой"<<endl;
    return 0;
}

