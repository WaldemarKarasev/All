#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <WinSock2.h>
#include <string>

#pragma warning(disable: 4996)

SOCKET Connections[100];
int Counter = 0;

void ClientHandler(int index)
{
    int msg_size;
    while (true)
    {
        recv(Connections[index], (char*)&msg_size, sizeof(int), NULL);
        char* msg = new char[msg_size + 1];
        msg[msg_size] = '\0';
        recv(Connections[index], msg, msg_size, NULL);
        for (int i = 0; i < Counter; i++)
        {
            if (i == index)
            {
                continue;
            }

            send(Connections[i], (char*)&msg_size, sizeof(int), NULL);
            send(Connections[i], msg, msg_size, NULL);
        }
        delete[]  msg;
    }
}

int main(int argc, char* argv[])
{
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0)
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }

    SOCKADDR_IN addr;
    int sizeOfAddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;

    SOCKET sLIsten = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sLIsten, (SOCKADDR*)&addr, sizeof(addr));
    listen(sLIsten, SOMAXCONN);

    SOCKET newConnection;
    for (int i = 0; i < 100; i++)
    {
        newConnection = accept(sLIsten, (SOCKADDR*)&addr, &sizeOfAddr);

        if (newConnection == 0)
        {
            std::cout << "Error #2\n";
        }
        else
        {
            std::cout << "Client Connected!\n";
            std::string msg = "Hello. It's my first network program!";
            int msg_size = msg.size();
            send(newConnection, (char*)&msg_size, msg_size, NULL);
            send(newConnection, msg.c_str(), msg_size, NULL);

            Connections[i] = newConnection;
            Counter++;
            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
        }
    }

    system("pause");
    return 0;
}
