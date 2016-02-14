import sys
MOD = 1000000007
def expo(a,n):
    result = 1
    while(n>0):
        if((n&1)):
            result = (result*a)%MOD
        a = (a*a)%MOD
        n >>= 1
    return result%MOD

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
   
    return (xLast + B)%B

t = int(sys.stdin.readline())
while(t>0):
    p,e = map(int,sys.stdin.readline().split())
    
    exp = expo(p,e-1)
    n = expo(p,e)
    sum = (p*(p-1)/2)%MOD
    X = (1 + ((exp*sum)%MOD*e)%MOD)%MOD
    Nr = ((n*n)%MOD + n - (2*X)%MOD + MOD*MOD)%MOD
    Dr = modInverse(2*(p-1),MOD)
    print (Nr*Dr)%MOD
    t -= 1
