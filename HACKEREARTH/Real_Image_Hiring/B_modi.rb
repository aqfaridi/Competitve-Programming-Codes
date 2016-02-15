def ceilindex(tailtable,l,r,k)
    while l < r
      m = (r + l)/2
      if tailtable[m] < k
          l = m + 1
      else
          r = m
      end
    end

    return l
end


t = gets.chomp.to_i
t.times do
  n = gets.chomp.to_i
  seq = gets.split(' ').slice(0, n).map(&:to_i)
  l = gets.chomp.to_i
  tailtable = Array.new(n,0)
  tailtable[0] = seq[0]
  len = 1
  ret = []
  
  for i in (1...n)
      if seq[i] < tailtable[0]
        tailtable[0] = seq[i]
      elsif seq[i] > tailtable[len-1]
        tailtable[len] = seq[i]
        len += 1
      else
        idx = ceilindex(tailtable,0, len-1, seq[i])
        tailtable[idx] = seq[i]
      end

      if len >= l
        ret.push(tailtable[l-1])
      end
  end

  if ret.empty?
    puts "-1"
  else
    puts ret.min
  end

end