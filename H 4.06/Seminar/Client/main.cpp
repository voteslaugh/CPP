#include "functions.h"

using namespace std;
using namespace sf;

int main() {
    TcpSocket socket;
    Packet packet;
    ConnectToServer(socket);
    while(true)
    {
        string login;
        cout<<"Type in user's login:    ";
        cin >> login;
        packet.clear();
        packet << login;
        if(socket.send(packet)!=Socket::Done)
        {
            cout << "Send error";
            continue;
        }
        if(socket.receive(packet)!= Socket::Done)
        {
            cout << "Recieve error";
        }
        packet.clear();
        if(socket.receive(packet)!= Socket::Done)
        {
            cout << "Recieve error";
        }
        bool flag;
        packet >> flag;
        if(flag)
        {
            printData(packet, login);
            continue;
        }
        else
        {
            packet.clear();
            userInPacket(packet);
            if(socket.send(packet)!=Socket::Done)
            {
                cout << "Unexpected error\n";
            }
            continue;
        }
    }
    return -1;
}