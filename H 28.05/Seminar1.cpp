#include <iostream>
#include <cmath>
using namespace std;
/*
Задача ««Углубление» функции»
Реализовать с использованием метапрограммирования шаблон функции, который позволил бы применять заданную функцию многократно.
*/
template<float (*func)(float), int n>
float deep( float x)
{
    for(int i=0; i<n; ++i)
    {
        x = func(x);
    }
    cout <<"Meaning of the function is " << x << endl;
    return x;
}

float Multip2(float a) { return 2 * a; }
float Sqrt(float a) { return sqrt(a); }
float Plus5(float a) { return a + 5; }
float Div2(float a) { return a / 2; }

int main()
{
    float a = 51.1;
    deep<Div2, 1>(a);
}