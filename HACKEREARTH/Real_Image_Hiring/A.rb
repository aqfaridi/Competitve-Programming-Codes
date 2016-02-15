N = gets.chomp.to_i
H = Hash.new 
(0...N).each do |i|
	str = gets.chomp
	str = str.chars.sort.join
	if H.has_key?(str)
		H[str] = H[str] + 1
	else
		H[str] = 1
	end 
end

puts H.values.max

=begin
H.each do |k,v|
	puts k , v
end
=end
