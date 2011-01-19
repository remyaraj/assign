# Future symbol generation
#Broker classes included

require "chronic"

$month = Hash[1=>"F",2=>"G",3=>"H",4=>"J",5=>"k",6=>"M",7=>"N",8=>"Q",9=>"U",10=>"V",11=>"X",12=>"Z"]

class FutureSymbol
	def initialize
		@future_symbol = Hash["ES"=>"","YM"=>"","GC"=>""]
		@time = Time.new
		@prefix = ""
		@underlying_symbol=""
		@expiry_date = Chronic.parse("Friday of third week of #{@time.month}")
		@expiry_month=""
		@year = @time.year
		@mod = 2000
		@current_date = Chronic.parse("now")
		@es_case = ["H","M","U","Z"]
		@gc_case = ["G","J","M","Q","V","X","Z"]
	end
	def expired?
		k = true
		k = false if @current_date<@expiry_date
		return k
	end
	def element?(element,month)
		k = false
		k = true if element == month
		return k
	end
	def expiry_month?(mon,case_set)
		case_set.each{|element|return true if element?(element,$month[mon])}
		return false
	end
	def case_value(mon,case_set,underlying_symbol)
		i=mon
		k=0
		while k<12
			break if expiry_month?(i,case_set)
			if i==12
				i=0
			else
				i=i+1
			end
			k = k+1
		end
		@expiry_month = $month[i]
		symbol = @prefix + underlying_symbol + @expiry_month + (@year.to_i() % @mod).to_s()
		return symbol
	end
	def get_symbol	
		k = @time.month
		k = k+1 if expired?
		@future_symbol["ES"] = case_value(k,@es_case,"ES")
		@future_symbol["YM"] = case_value(k,@es_case,"YM")
		@future_symbol["GC"] = case_value(k,@gc_case,"GC")
		
		return @future_symbol
	end
end

class OptionsXpress < FutureSymbol

end

class TradeStation < FutureSymbol

end

class PFGBest < FutureSymbol
	def initialize
		super()
		@mod = 10
	end
end

class MBTTrading < FutureSymbol
	def initialize
		super()
		@mod = 10
		@prefix = "/"
	end
end

k = MBTTrading.new
j= k.get_symbol
puts j["ES"]
puts j["YM"]
puts j["GC"]

