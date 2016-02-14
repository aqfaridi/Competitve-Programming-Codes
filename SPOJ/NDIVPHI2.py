import sys
primes = [2]
MAX = 40000
sqrLim = 200
Lim = (MAX-3)/2 + 1 
flag = [True] * Lim
dp = []
def sieve():
    for i in range(3,sqrLim+1,2):
        if(flag[i]):
            for j in range(i*i,MAX+1,i):
                if(j%2):#odd multiple
                    flag[(j-3)/2] = False
                
    for i in range(0,Lim):#values are coming
        if(flag[i]):
            primes.append(2*i+3)
    l = len(primes)
    dp.append(2)
    for i in range(1,l):
        dp.append(primes[i]*dp[i-1])
   
    #print len(primes)        

sieve()
t = int(sys.stdin.readline())
while(t>0):
    n = int(sys.stdin.readline())
    if(n==1 or n==0):
        print n
        t -= 1
        continue
    low = 0
    high = len(dp) - 1
    while(low <= high):
        mid = (low+high)//2
        if(dp[mid] == n):
            break;
        if(dp[mid] > n):
            high = mid - 1
        else: 
            low = mid + 1
    if(dp[mid] > n):
        mid -= 1
    print dp[mid]
    t = t-1


