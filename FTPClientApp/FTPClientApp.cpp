// FTP Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#define PORT 21
#define BUFFER_SIZE 1024

class FTPClient {
private:
    SOCKET sock;  // Winsock socket type for Windows
    std::string hostname;

public:
    FTPClient(const std::string& host) : hostname(host), sock(INVALID_SOCKET) {}

    // Initialize Winsock 
    bool initialize_winsock() {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            std::cerr << "WSAStartup failed." << std::endl;
            return false;
        }
        return true;
    }

    // Create and connect the socket
    bool connect_to_server() {
        struct addrinfo hints, * server_info;

        // Prepare the hints structure for getaddrinfo
        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_INET;  // Use IPv4
        hints.ai_socktype = SOCK_STREAM;  // TCP stream socket

        // Get the server address info
        if (getaddrinfo(hostname.c_str(), "21", &hints, &server_info) != 0) {
            std::cerr << "ERROR resolving hostname" << std::endl;
            return false;
        }

        // Create socket
        sock = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
        if (sock == INVALID_SOCKET) {
            std::cerr << "ERROR opening socket" << std::endl;
            freeaddrinfo(server_info);
            return false;
        }

        // Connect to server
        if (connect(sock, server_info->ai_addr, (int)server_info->ai_addrlen) < 0) {
            std::cerr << "ERROR connecting to server" << std::endl;
            freeaddrinfo(server_info);
            return false;
        }

        // Clean up server info structure
        freeaddrinfo(server_info);

        return true;
    }

    // Send command to the server
    void send_command(const std::string& command) {
        send(sock, command.c_str(), (int)command.length(), 0);
        std::cout << "Client: " << command;
    }

    // Receive response from the server
    void receive_response() {
        char buffer[BUFFER_SIZE];
        std::memset(buffer, 0, BUFFER_SIZE);
        recv(sock, buffer, BUFFER_SIZE - 1, 0);
        std::cout << "Server: " << buffer << std::endl;
    }

    // Login with username and password
    void login(const std::string& username, const std::string& password) {
        std::string command = "USER " + username + "\r\n";
        send_command(command);
        receive_response();

        command = "PASS " + password + "\r\n";
        send_command(command);
        receive_response();
    }

    // List the contents of the directory
    void list_directory() {
        send_command("LIST\r\n");
        receive_response();
    }

    // Close the connection
    void close_connection() {
        send_command("QUIT\r\n");
        receive_response();
        closesocket(sock);
        WSACleanup();  // Cleanup Winsock resources
    }
};

int main() {
    std::string hostname = "ftp.dlptest.com";  // Example public FTP server
    std::string username = "dlpuser";
    std::string password = "rNrKYTX9g7z3RgJRmxWuGHbeu";

    // Create FTP client instance
    FTPClient ftpClient(hostname);

    // Initialize Winsock
    if (!ftpClient.initialize_winsock()) {
        return 1;
    }

    // Connect to the FTP server
    if (!ftpClient.connect_to_server()) {
        std::cerr << "Failed to connect to FTP server." << std::endl;
        return 1;
    }

    // Receive server greeting
    ftpClient.receive_response();

    // Login with username and password
    ftpClient.login(username, password);

    // List the directory contents
    ftpClient.list_directory();

    // Close the connection
    ftpClient.close_connection();

    return 0;
}

