def binary_search(arrp,low,high,key)
	while low < high
		mid = (low + high)/2
		if arrp[mid] < key
			low = mid + 1
		else
			high = mid
		end
	end
	return low
end


testcase = gets
parse = testcase.chomp
testcases = parse.to_i

testcases.times do 
	numbers = gets.chomp.to_i
	
	arry = gets.split(' ').slice(0,numbers).map {|x| x.to_i}
	lbounds = gets.chomp.to_i
	
	arr = Array.new(numbers,0)
	arr[0] = arry[0]
	
	tail = 1
	answer = []
	
	for index in (1..numbers-1)
		if( arry[index] < arr[0])
			arr[0] = arry[index ]
		elsif(arr[tail-1] < arry[index] )
			arr[tail] = arry[index]
			tail = tail + 1
		else
			i = binary_search(arr,0,tail-1,arry[index])
			arr[i] = arry[index]
		end
	
		if(tail >= lbounds)
			answer.push(arr[tail-1])
		end
	end
	
	if answer.empty?
		puts "-1"
	else
		puts answer.min
	end
	
end