#TCP echo server

require 'socket'

server = TCPServer.new('127.0.0.1',8000)
socket = server.accept
loop do
	socket.puts socket.readline
end

