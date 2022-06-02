#pragma once
#include <string>
using namespace std;

struct Data{
    Data(string login, string surname, string gender, size_t age) :login(login), surname(surname), gender(gender), age(age){}
    Data(){}
    string login;
    string surname;
    string gender;
    size_t age;
};

class User{
    Data data;
public:
    User(Data data):data(data){};

    const Data& getData()const{
        return data;
    }

};
