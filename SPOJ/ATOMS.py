t = int(raw_input())
while(t>0):
    try:
        str = raw_input()
       
        if(len(str)==0):
            continue

        s = str.split(' ')
       
        n = int(s[0])
        k = int(s[1])
        m = int(s[2])

        if(k*n > m):
            print 0
            continue

        for i in range(1,64):
            if(n*(k**i) > m):
                print i-1
                break 
                
        t-=1
    except:
        break
