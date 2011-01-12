
from socket import *


while 1:	
	fd = socket(AF_INET,SOCK_STREAM)
	fd.connect(('127.0.0.1',8000))
#	fd.send(raw_input())
#	data = fd.recv(100)
#	print data
#	fd.close()

