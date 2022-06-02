#include <SFML/Network.hpp>
#include "User.h"
#include <iostream>
#include <map>
using namespace std;
using namespace sf;

int main() {
    map <string, User*> Users;
    Users["admin"] = new User(Data{"admin", "Vladik", "Helicopter", 19});
    TcpListener listener;
    TcpSocket socket;
    Packet packet;
    string login;
    size_t port = 55555;
    Socket::Status status;
    cout<<"Public IP is:  " << IpAddress::getPublicAddress() << "\n"
    << "Local IP is:  " << IpAddress::getLocalAddress() << "\n"
    << "Port is:  " << port << "\n";
    while(true) {
        packet.clear();
        if (socket.send(packet) != Socket::Done) { //Проверяем связь с пользователем
            listener.listen(port);  //если не подключен, ждём подключения
            if (listener.accept(socket) != Socket::Done) {
                cout << "Unexpected error" << endl;
                continue;
            }
            socket.send(packet); //Для обработки "ненужного" пакета
        }
        packet.clear();
        if (socket.receive(packet) != Socket::Done) {
            cout << "Didn't get any packets" << endl;
            continue;
        }
        packet >> login;
        cout<<login << endl;
        bool flag;
        if (Users.find(login) != Users.end()) {
            flag = true;
            Data data = Users.at(login)->getData();
            packet.clear();
            packet << flag << data.surname << data.gender << data.age;
            if (socket.send(packet) != Socket::Done) {
                cout << "Send error" << endl;
            }
            continue;
        } else {
            flag = false;
            packet.clear();
            packet << flag;
            if (socket.send(packet) != Socket::Done) {
                cout << "Send error" << endl;
            }
            packet.clear();
            if (socket.receive(packet) != Socket::Done) {
                cout << "Didn't get registration data" << endl;
            }

            Data data;
            packet >> data.surname >> data.gender >> data.age;
            Users[login] = new User(data);
            continue;
        }
    }
    return -1;
}