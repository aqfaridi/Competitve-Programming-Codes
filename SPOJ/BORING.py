import sys
def modInverse(a,b):
    xLast = 1
    x = 0
    yLast = 0
    y = 1
    while(b>0):
        q = a/b
        r = a%b
        m = xLast - q*x
        n = yLast - q*y
        xLast = x
        yLast = y
        x = m
        y = n
        a = b
        b = r
    return xLast

fact = [1]
def factorial(n):
    for i in range(1,n):
        fact.append(fact[i-1] * i);

factorial(10001)

t = int(sys.stdin.readline())
while(t>0):
    n,p = map(int,sys.stdin.readline().split())
    if(n>=p):
        print 0
        t-=1
        continue;
    neg = 1
    k = p-n    
    if((k&1)):
        neg = -1
    pro = p + neg*((fact[k-1]%p))    
    ans = (modInverse(pro,p) + p)%p
    print ans
    t -= 1

