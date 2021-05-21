def recieve(client_sock):
    data = client_sock.recv(1024)
    size_b = data[:4:]
    text_b = data[4::]
    size = int.from_bytes(size_b, byteorder='little')
    #print("receive:", "data", data, "end_data")
    #print("receive:", size, text_b)

    if size != 0 and text_b == b'':
        #print("receive: no data, trying again..")
        data = client_sock.recv(1024)
        text_b = data

    #print("receive:", "data", data, "end_data")
    #print("receive:", size, text_b)
    text = text_b.decode('utf-8')

    return size, text, data



import socket
import select

serv_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, proto=0)
serv_sock.bind(('127.0.0.1', 5678))
serv_sock.listen(10)

while True:
    # Бесконечно обрабатываем входящие подключения
    client_sock, client_addr = serv_sock.accept()
    print('Connected by', client_addr)
    while True:
        # Пока клиент не отключился, читаем передаваемые
        # им данные и отправляем их обратно
        size, text, data = recieve(client_sock)

        print(size, text)
        if size == 0:
            print("closing socket")
            break
        client_sock.send(bytes('Hello from server!', encoding='UTF-8'))

    client_sock.close()
    break


serv_sock.close()
print("Server stopped! Thank you for using!")
