const net = require("net");

let clientId = 0;
const clients = {};

function handleClient(socket) {
  clientId++;
  const currentClientId = clientId;
  clients[currentClientId] = socket;

  console.log(
    `New client connected: ${socket.remoteAddress}, assigned ID: ${currentClientId}`
  );

  socket.write(`Welcome, Client #${currentClientId}\n`);

  socket.on("data", (data) => {
    console.log(`Received from Client #${currentClientId}: ${data}`);
    socket.write(`Client #${currentClientId}: Message received!\n`);
  });

  socket.on("end", () => {
    console.log(`Client #${currentClientId} has disconnected`);
    delete clients[currentClientId];
  });

  socket.on("close", () => {
    console.log(`Client #${currentClientId} connection closed`);
    delete clients[currentClientId];
  });

  socket.on("error", (err) => {
    console.error(`Client #${currentClientId} error:`, err.message);
    delete clients[currentClientId];
  });
}

const server = net.createServer(handleClient);

server.listen(9999, () => {
  console.log("Server listening on port 9999...");
});
