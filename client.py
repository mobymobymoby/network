import socket
import sys

if len(sys.argv) != 2:
    print(f"Usage: python {sys.argv[0]} <TARGET_PORT>")
    exit(1)

TARGET_IP = "127.0.0.1"
TARGET_PORT = int(sys.argv[1])

client_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_sock.connect((TARGET_IP, TARGET_PORT))

client_sock.send(b"Hello")

client_sock.close()
