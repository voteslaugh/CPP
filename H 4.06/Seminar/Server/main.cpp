#include "Server.h"
#include <iostream>
using namespace std;
using namespace sf;

int main() {
    string login;
    sf::Packet packet;
    Server server;
    cout<<"Public IP is:  " << IpAddress::getPublicAddress() << "\n"
    << "Local IP is:  " << IpAddress::getLocalAddress() << "\n"
    << "Port is:  " << server.port << "\n";

    while(true) {
        if (server.sendPacket(packet) != Socket::Done) { //Проверяем связь с пользователем
            if (server.toConnect() != Socket::Done) {
                cout << "Unexpected connect error" << endl;
                continue;
            }
            server.sendPacket(packet); //Для обработки "ненужного" пакета
        }
        if (server.receivePacket(packet) != Socket::Done) {
            cout << "Didn't get any packets" << endl;
            continue;
        }
        packet >> login;
        cout<<"Request received:    "<<login << endl; //just to check login
        if(server.packData(login, packet)){
            server.sendPacket(packet);
            continue;
        }
        else{
            server.sendPacket(packet);
            if(server.receivePacket(packet)!=sf::Socket::Status::Done)
                continue;
            server.userRegistration(packet, login);
            continue;
        }
    }
    return -1;
}