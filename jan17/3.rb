#UDP client

require 'socket'

log = UDPSocket.new
log.connect("127.0.0.1",8000)

log.print "Message send"
