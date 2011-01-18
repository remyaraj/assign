class Prime
	def initialize
		@prime_arr = Array.new
	end
	def get_primes(limit)
		for i in 2..limit
			k=0
			for j in 2..i/2
				if (i%j)==0
					k = 1
					break
				end
			end
			if k==0
				@prime_arr.push(i)
			end
		end
		return @prime_arr
	end
end

k = Prime.new
k.get_primes(10).each{|x| puts x}
