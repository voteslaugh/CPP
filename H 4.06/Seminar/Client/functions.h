#pragma once
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

void ConnectToServer(TcpSocket& socket)
{
    Socket::Status status;
    size_t port;
    string ip;
    while(true) {
        cout << "Type in ip:" << endl;
        cin >> ip;
        cout << "Type in port:" << endl;
        cin >> port;
        status = socket.connect(ip, port);
        if (status != Socket::Done) {
            cout << "Connect error" << endl;
        }
        else
        {
            return;
        }
    }
}

void printData(Packet &packet, const string &login)
{
    string surname,gender;
    size_t age;
    packet >> surname >> gender >> age;
    cout<<"Found user with login " << login << ":" << "\n"
        <<"  Surname is:   " <<  surname << "\n"
        << "    Gender is:    " <<gender<<"\n"
        << "   Age is:    " << age << "\n";
}

void userInPacket(Packet &packet)
{
    string surname, gender;
    size_t age;
    cout<< "User was not found. Creating new user. \nType in surname:   ";
    cin>>surname;
    cout<<"\nType in gender:    ";
    cin>>gender;
    cout<<"\ntype in age:   ";
    cin>>age;
    packet << surname << gender << age;
}

