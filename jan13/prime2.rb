class Prime
	def initialize(limit)
		@prime_len = limit
	end
	def prime?(i)
		k=true
		2.upto(i/2){|j| k=false if (i%j)==0}
		return k
	end
	def each
		2.upto(@prime_len){|i| yield(i) if prime?(i)}
	end
end

k = Prime.new(10)
k.each{|x| puts x}

#opening a file will return a object
#chomp to strip of the trailing newline
File.open("songdata") {|song_file| song_file.each{|line| puts line.chomp.split(/\s*\|\s*/)}}
