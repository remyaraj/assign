#final parser class

class Parser
	def initialize(parse_obj,write_obj)
		@parse_obj = parse_obj
		@array_match = Array.new
		@final_array = Array.new
		@write_obj = write_obj
	end
	def proto_match?(line,proto)
		k = false
		k = true if line.match(/^(:\s)#{proto}(.*)/)
		return k
	end
	def name_value(line,name)
		k = line.split(/,/)
		k.each{|value| @final_array.push(value) if value.match(/(?i)#{name}=(.*)/)}
	end
	def name_match(name)
		@array_match.each{|line|  name_value($&,name.chomp) if line.match(/#(.*),(?i)#{name.chomp}=(.*),(.*)#/)}
	end		
	def line_match(proto)
		@parse_obj.each do|line|
			@array_match.push($&) if line.match(/(:\s(\d{3})(.*)<(.*)>##(.*)##)$/) && proto_match?($&,proto.chomp)
		end
	end
	def file_write
		@final_array.each{|line| @write_obj.write("#{line}\n")}
	end
end

File.open("parsed_data",'w')do|f|
	File.open("server.log")do|parse_obj|
		parse = Parser.new(parse_obj,f)
		parse.line_match(gets)
		parse.name_match(gets)
		parse.file_write
	end
end
