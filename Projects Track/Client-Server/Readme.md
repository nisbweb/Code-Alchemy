# Node.js Client-Server Program

This project demonstrates a simple client-server program using Node.js. The server can handle multiple clients simultaneously, assigning each client a unique ID and responding to their messages. The server also tracks when clients connect and disconnect.

## Table of Contents
1. [Features](#features)
2. [How It Works](#how-it-works)
3. [Setup Instructions](#setup-instructions)
4. [Usage](#usage)
5. [Server Functions](#server-functions)
6. [Client Functions](#client-functions)
7. [Example Interaction](#example-interaction)
8. [Dependencies](#dependencies)
9. [License](#license)

---

## Features

- **Multi-client support**: The server can handle multiple clients concurrently.
- **Unique Client ID**: Each client is assigned a unique ID when they connect.
- **Message Acknowledgment**: The server acknowledges every message received from a client with the client's ID.
- **Client Connection Management**: The server logs when clients connect and disconnect, handling disconnections gracefully.
- **Console-based interaction**: Clients can send messages to the server via the terminal.

---

## How It Works

1. **Server**:
   - The server runs on a specific port (`9999` in this case).
   - It listens for incoming client connections and assigns each client a unique ID.
   - When a client sends a message, the server responds with a confirmation message including the client's ID.
   - The server tracks client connections and logs when a client disconnects or the connection is forcibly closed.

2. **Client**:
   - Clients connect to the server on the same port (`9999`).
   - Once connected, they can send messages to the server via the console.
   - The server will respond with an acknowledgment message, and the client can keep sending messages until they type `exit` to disconnect.

---

## Setup Instructions

### Prerequisites:
- **Node.js** installed on your machine.
  - [Download Node.js](https://nodejs.org/)

### Steps:
1. Clone this repository or copy the provided files.
2. Navigate to the project directory in your terminal.

### Install the necessary dependencies (if any):
For this project, the built-in `net` module of Node.js is used, so no additional dependencies are required.

---

## Usage

### Running the Server:
1. Open a terminal and navigate to the project directory.
2. Run the server using the following command:
   ```bash
   node server.js
   ```

### Running the Client:
1. Open a new terminal window or tab for each client you want to run.
2. In each terminal, run the client using the following command:
   ```bash
   node client.js
   ```

3. Once connected, you can send messages to the server through the client terminal.
4. To disconnect the client, type `exit`.

---

## Server Functions

1. **handleClient(socket)**:
   - This function is called for each client that connects.
   - It assigns a unique ID to each client, logs their connection, and handles messages and disconnections.

2. **Client Identification**:
   - Each client is assigned a unique ID when they connect, which is stored in the `clients` object for easy tracking.

3. **Message Handling**:
   - The server listens for data from the client using `socket.on('data')` and responds with an acknowledgment message that includes the client’s unique ID.

4. **Disconnection Handling**:
   - The server listens for `socket.on('end')` to detect when a client disconnects gracefully.
   - `socket.on('close')` is used to detect if the connection is forcibly closed.

5. **Error Handling**:
   - If there is an error during the connection or communication, the server logs the error and removes the client from the active list.

---

## Client Functions

1. **sendMessage()**:
   - This function prompts the user to input a message, sends it to the server, and then waits for another input.
   - The client keeps interacting with the server until the user types `exit`.

2. **Server Response Handling**:
   - The client listens for `data` from the server and displays the acknowledgment message received.

3. **Disconnection**:
   - If the user types `exit`, the client disconnects by calling `client.end()`.

---

## Example Interaction

### **Server Output:**
```bash
Server listening on port 9999...
New client connected: ::1, assigned ID: 1
Received from Client #1: Hello Server
Client #1 has disconnected
New client connected: ::1, assigned ID: 2
Received from Client #2: Hi Server
Client #2 connection closed
```

### **Client Output:**

- **Client 1**:
    ```bash
    Connected to server
    Server response: Welcome, Client #1
    Enter message to send: Hello Server
    Server response: Client #1: Message received!
    Enter message to send: exit
    Disconnected from server
    ```

- **Client 2**:
    ```bash
    Connected to server
    Server response: Welcome, Client #2
    Enter message to send: Hi Server
    Server response: Client #2: Message received!
    Enter message to send: exit
    Disconnected from server
    ```

---

## Dependencies

- **Node.js**: The `net` module is used to create the TCP server and client. This module is built into Node.js, so no external libraries are required.

---
