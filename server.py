import socket
import sys

if len(sys.argv) != 2:
    print(f"Usage: python {sys.argv[0]} <OPEN_PORT>")
    exit(1)

IP = "127.0.0.1"
PORT = int(sys.argv[1])

server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_sock.bind((IP, PORT))
server_sock.listen(1)

print(f"Server: {IP}:{PORT}")
connection_sock, addr = server_sock.accept()
print(f"New client: {addr[0]}:{addr[1]}")

msg = connection_sock.recv(1000)
print("Msg: ", msg)

server_sock.close()
