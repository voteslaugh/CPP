﻿#include <iostream>
#include <vector>
#include <stack>
#include <map>
void strToVector(std::vector <char> &vec, const std::string &s)
{
    for (auto c : s)
        vec.push_back(c);
}

void printVec(const std::vector <char> &vec)
{
    std::cout << "Your data is:" << std::endl;
    for (auto c : vec)
        std::cout << c;
    std::cout << std::endl;
}



typedef class PolishNotation
{
public:
    std::map <char, int> dict;
    std::stack <char> stack;
    std::vector <char> pData; //данные в форме польской нотации
    std::vector <char> data; //данные в инфиксной форме
    PolishNotation() {
        this->pData = {}; this->dict['('] = 1, this->dict[')'] = 4, this->dict['*'] = 3, this->dict['/'] = 3, this->dict['-'] = 2, this->dict['+'] = 2;
    }
    PolishNotation(std::string s)
    {
        this->dict['('] = 1, this->dict[')']=4, this->dict['*'] = 3, this->dict['/'] = 3, this->dict['-'] = 2, this->dict['+'] = 2;
        strToVector(this->data, s);
    }

    void poling()
    {
        for (int i = 0; i < data.size(); i++) {
            char x = data[i];
            if (dict[x] == 0)
                this->pData.push_back(x);
            else
            {
                if ((this->stack.empty() == true) || (dict[x] == 1) || (dict[stack.top()] < dict[x])) {

                    if (dict[x] == 4)
                    {
                        char y = stack.top();
                        while (dict[y] != 1)
                        {
                            pData.push_back(y);
                            stack.pop();
                            y = stack.top();
                        }
                        stack.pop();
                    }
                    else
                        stack.push(x);
                }
                else if (dict[stack.top()] >= dict[x])
                {
                    char top = stack.top();
                    do{
                        pData.push_back(top);
                        stack.pop();
                        if (stack.empty() == false) top = stack.top();
                    } while ((dict[top] >= dict[x]) && (dict[top] != 1) && (!stack.empty()));
                        stack.push(x);
                }
            }
        }
        while (!stack.empty()) {
            pData.push_back(stack.top());
            stack.pop();
        }
    }
}Pol;

int main()
{
    std::string s;
    std::cin >> s;
    Pol pol(s);
    pol.poling();
    printVec(pol.pData);
}
    