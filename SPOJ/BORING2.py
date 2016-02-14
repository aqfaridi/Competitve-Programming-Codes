import sys
import math
import sys
primes = [2]
MAX = 1000010
sqrLim = 1001
Lim = (MAX-3)/2 + 1 
flag = [True] * Lim
def sieve():
    for i in range(3,sqrLim+1,2):
        if(flag[(i-3)/2]):
            for j in range(i*i,MAX+1,i):
                if(j%2):#odd multiple
                    flag[(j-3)/2] = False
                
    for i in range(0,Lim):#values are coming
        if(flag[i]):
            primes.append(2*i+3)
sieve()

def expo(a,n,p):
    result = 1
    while(n>0):
        if((n&1)):
            result = (result*a)%p
        a = (a*a)%p
        n >>= 1
    return result%p

def modInverse(a,b):
    #ax + by = gcd(a,b)
    #r(i) = r(i-2) - q(i)*r(i-1)
    B = b
    xLast,yLast,x,y = 1,0,0,1
    while(b):
        q = a//b
        r = a%b
        m = xLast - q*x
        n = yLast - q*y
        xLast,yLast,x,y,a,b = x,y,m,n,b,r
    return (xLast+B)%B


def factorize(n,p):
    i = 0
    pro = 1
    #for all primes upto n
    while(primes[i] <= n):
        # how many multiples of primes[i] in n!
        pwr = primes[i]
        cnt = 0
        while(pwr <= n):
            cnt += (n//pwr)
            pwr *= primes[i]
        if(cnt > 0):
            pro = (pro * expo(primes[i],cnt,p))%p
        i += 1
    return pro


t = int(sys.stdin.readline())
while(t>0):
    n,p = map(int,sys.stdin.readline().split())
    if(n>=p):
        print 0
        t-=1
        continue

    neg = 1
    k = p-n    
    if((k&1)):
        neg = -1
    #factorize (k-1)! mod p using legendre theorem
    f = factorize(k-1,p)  
    inverse = modInverse(f,p)
    ans = (p + inverse*neg)%p
    print ans
    t -= 1

