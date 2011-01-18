class Prime
	def initialize(limit)
		@prime_arr = Array.new
		for i in 2..limit
			k=0
			for j in 2..i/2
				if (i%j)==0
					k=1
					break
				end
			end
			if k==0
				@prime_arr.push(i)	
			end
		end
	end
	def each
		for i in 0...@prime_arr.length	
			yield(@prime_arr[i])
		end
	end
end

k = Prime.new(10)
k.each{|x| puts x}
