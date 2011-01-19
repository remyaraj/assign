# Future symbol generation
#Broker classes included
#randomization of future symbols

require "future_symbol.rb"

class MBTrading < FutureSymbol
	def initialize
		super()
		@mod = 10
		@prefix = "/"
	end
end
