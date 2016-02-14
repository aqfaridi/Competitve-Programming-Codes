import sys
def expo(a,n,p):
    result = 1
    while(n>0):
        if((n&1)):
            result = (result*a)%p
        a = (a*a)%p
        n >>= 1
    return result%p


t = 3
while(t>0):
    D,p = map(int,sys.stdin.readline().split())
    f = 1
    for i in range(2,p-D+1):
        f  = (f*i)%p
    print f
    t -= 1






