def gcd(a,b):
    if(b == 0):
        return a
    else:
        return gcd(b,a%b)

t = input()
while(t > 0):
    n = input()
    s = raw_input().split(' ')
    parent = [0]
    for i in range(n):
        parent.append(int(s[i]))     
    
    mark = [0]*(n+1)
    l = 1
    for i in range(1,n+1):
        if(mark[i] == 0):
            ptr = parent[i]
            cnt = 0
            while(True):
                cnt += 1
                mark[ptr] = 1
                ptr = parent[ptr]
                if(ptr == parent[i]):
                    break
            l = (l*cnt) / gcd(l,cnt)
    print l%1000000007  
    t -= 1
