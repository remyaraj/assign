
from socket import *
fd = socket(AF_INET,SOCK_STREAM)
fd.connect(('127.0.0.1',8000))
while 1:
	fd.send("hai")
	data = fd.recv(100)
	print data
fd.close()

