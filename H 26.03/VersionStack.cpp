#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
using namespace std;
template<typename T>
class Stack
{
    vector<T> v;
    map<int, vector<T>> list; int k = 0;
public:
    void push(T elem)
    {
        change();
        v.push_back(elem);  //o(1)
    };
    T pop()
    {
        change();
        T elem = v.back(); //o(1)
        v.pop_back();
        return elem;
    }
    void show()
    {
        cout << "stack:";
        for (auto e : v) cout << e << " "; //o(n)
        cout << endl;
    }
    void change()
    {
        list[k] = v; //o(1)
        k++;
    }

    void rollback(int num)
    {
            this->v = list[num];  //o(1)
    }
    void forget()
    {
        list.clear(); //o(1)
    }
};

int main() {
    Stack<int> a;
    a.push(1);  a.push(2);  a.push(3);
    a.show();
    cout << "poped:" << a.pop() << endl;
    a.show();
    a.rollback(3);
    a.show();
    return 0;
}
