# Future symbol generation
#Broker classes included
#randomization of future symbols

require "future_symbol.rb"

class PFGBest < FutureSymbol
	def initialize
		super()
		@mod = 10
	end
end
