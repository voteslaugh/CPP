#include "PolishNotationClass.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string s;
    std::cout << "Введите нужную строку" << std::endl;
    std::cin >> s;
    Pol poli(s);
    poli.poling();
    int answ = poli.solution();
    std::cout << "Ответ: "<< answ << std::endl;

}
    