import sys
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
    xLast = 1
    yLast = 0
    x = 0
    y = 1
    while(b):
        q = a//b
        r = a%b
        m = xLast - q*x
        n = yLast - q*y
        xLast = x 
        yLast = y
        x = m 
        y = n
        a = b
        b = r
   
    return (xLast+B)%B
def egcd(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q,r = b//a,b%a; m,n = x-u*q,y-v*q # use x//y for floor "floordivision"
        b,a, x,y, u,v = a,r, u,v, m,n
    return b, x, y
def modinv(a, m):
    g, x, y = egcd(a, m) 
    if g != 1:
        return None
    else:
        return x % m
t = 100
while(t>0):
    D,p = map(int,sys.stdin.readline().split())
    if(D==0):
        t -= 1      
        print 0 
        continue

    neg = 1 
    if(D % 2 == 1):
        neg = -1            
    f = 1
    for i in xrange(2,D):
        f = (f*i)%p
    inverse = modinv(f,p)
    ans = (p + neg*inverse)%p
    print ans
    t -= 1


