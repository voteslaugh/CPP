#pragma once
#include "User.h"
#include <map>
#include <SFML/Network.hpp>

using mapData=map <string, User*>;
class Server{
    sf::TcpSocket socket;
    sf::TcpListener listener;
    mapData Users;
public:
    const size_t port = 55555;
    Server(){
        listener.listen(port);
        Users["admin"] = new User(Data{"admin", "Vladik_Zubkov", "Helicopter", 19});
    }

    sf::Socket::Status sendPacket(sf::Packet &packet){
        return socket.send(packet);
    }

    sf::Socket::Status receivePacket(sf::Packet &packet){
        packet.clear();
        return socket.receive(packet);
    }

    sf::Socket::Status toConnect()
    {
        return listener.accept(socket);
    }

    bool packData(const string &login, sf::Packet &packet){
        packet.clear();
        if(Users.find(login)!=Users.end()){
            Data data = Users.at(login)->getData();
            packet << true << data.surname << data.gender << data.age;
            return true;
        }
        else{
            packet<<false;
            return false;
        }
    }

    void userRegistration(sf::Packet &packet, const string &login){
        Data data;
        packet >> data.surname >> data.gender >> data.age;
        Users[login] = new User(data);
    }

};
