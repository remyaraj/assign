#TCP echo server
# handling multiple client

require 'socket'
require 'thread'
require 'thwait'

group = ThreadsWait.new
server = TCPServer.new('127.0.0.1',8000)
while((socket = server.accept))
	thread = Thread.new(socket)do|socket| 
	socket.puts socket.readline while true
	end
	group.join_nowait(thread)
end
group.all_waits

