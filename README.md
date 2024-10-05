# FTP Client in C++ using Winsock

This project implements a simple FTP (File Transfer Protocol) client using Winsock for Windows. The client allows you to connect to an FTP server, log in with a username and password, list directory contents, and close the connection.

## Features

- Connects to an FTP server via TCP on port 21
- Sends basic FTP commands (USER, PASS, LIST, QUIT)
- Receives and displays server responses
- Supports listing of directory contents
- Gracefully closes the connection and cleans up Winsock resources

## Prerequisites

- Windows operating system
- Microsoft Visual Studio or any C++ IDE that supports Winsock
- Basic understanding of C++ and networking concepts

## How to Build

1. Clone the repository or download the source code.
2. Open the project in your preferred IDE (e.g., Microsoft Visual Studio).
3. Make sure you have the `ws2_32.lib` library linked in your project settings as it is required for Winsock functions.
4. Build the project.

## How to Run

1. After building the project, run the executable. The client will:
   - Initialize Winsock.
   - Connect to the FTP server.
   - Log in using the provided credentials.
   - List the contents of the directory.
   - Close the connection.

### Example Usage

The program connects to a public FTP server (`ftp.dlptest.com`) with the username `dlpuser` and password `rNrKYTX9g7z3RgJRmxWuGHbeu`:

```bash
Client: USER dlpuser
Server: 331 User dlpuser OK. Password required
Client: PASS rNrKYTX9g7z3RgJRmxWuGHbeu
Server: 230 OK. Current restricted directory is /
Client: LIST
Server: drwxr-xr-x   2 ftp      ftp          4096 Mar 18 2021 test-directory
Client: QUIT
Server: 221 Goodbye.
