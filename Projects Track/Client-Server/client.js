const net = require("net");
const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const client = net.createConnection({ port: 9999 }, () => {
  console.log("Connected to server");
});

client.on("data", (data) => {
  console.log(`Server response: ${data}`);
  sendMessage();
});

function sendMessage() {
  rl.question("Enter message to send: ", (message) => {
    if (message.toLowerCase() === "exit") {
      client.end();
    } else {
      client.write(message);
    }
  });
}

client.on("end", () => {
  console.log("Disconnected from server");
  rl.close();
});

client.on("error", (err) => {
  console.error("Client error:", err.message);
});
