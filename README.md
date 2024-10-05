FTP Client Application

Overview
This project implements a simple FTP (File Transfer Protocol) client using C++ and the Winsock library on the Windows platform. The client is capable of connecting to an FTP server, navigating the file system, and transferring files. 

Features
File Download: Retrieve files from the server.
File Upload: Upload files to the server.
File System Navigation: Browse and navigate directories on the server.
Winsock API: Utilizes the Winsock API for network communication on Windows.

Installation
Clone the repository:
bash
git clone https://github.com/Jeremiah-Sakuda/FTPClientApp.git

Build the Project:
Open the project in your preferred C++ IDE.
Ensure that you have the Winsock development library installed.
Compile and build the project.

Usage
Run the application:
Execute the compiled FTP client.
Provide the server's IP address and port to connect.

Commands:
GET [filename]: Download a file from the server.
PUT [filename]: Upload a file to the server.
LIST: List the files in the current directory.
CD [directory]: Change the directory on the server.
PWD: Print the working directory.
QUIT: Close the connection and exit the application.

Challenges and Solutions
Network Latency: Handling network delays during file transfers by implementing timeout mechanisms.
Concurrency: Managing multiple file transfers simultaneously using multi-threading.

Future Enhancements
GUI Support: Add a graphical user interface for ease of use.
Extended Protocols: Support for additional protocols like SFTP (Secure FTP).
Cross-Platform Compatibility: Adapt the application to work on Linux and macOS.
