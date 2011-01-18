#not complete

require 'gserver'

class TimeServer < GServer
 def initialize(port)
	super(port)
	@count = 3
 end
 def serve(client)
	client.puts Time.now.to_s
	@count -=1
	stop if count.zero?
 end
end

server = TimeServer.new(8000)
server.audit = true
server.start
server.join




