#parse a file
File.open("parsed_data",'w') do |f|
File.open("server.log") do |pars_obj|
	pars_obj.each do |line|
		f.write("#{$&}#{$'}\n")if line.match(/(:\s(\d{3})(.*)<(.*)>##(.*)##)$/) && $&.match(/^(:\s566)/)
	end
end
end
