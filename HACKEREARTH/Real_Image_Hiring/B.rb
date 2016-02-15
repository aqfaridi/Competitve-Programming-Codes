t = gets.chomp.to_i
t.times do
  n = gets.chomp.to_i
  seq = gets.split(' ').slice(0, n).map(&:to_i)
  l = gets.chomp.to_i

  ans = Array.new(n,1)

  (0...n).each do |i|
    (0...i).each do |j|
      if seq[i] > seq[j] && ans[i] < ans[j] + 1
        ans[i] = ans[j] + 1
      end
    end
  end

  ret = []
  (0...n).each do |i|
    if(ans[i] >= l)
      ret.push(seq[i])
    end
  end

  #puts ret

  if ret.empty?
    puts "-1"
  else
    puts ret.min
  end

end

