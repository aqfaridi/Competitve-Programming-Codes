import sys
t = int(sys.stdin.readline())
MOD = 1000000007
def expo(a,b):
    result = 1;
    while(b):
        if(b&1):
            result = (result*a)%MOD
        a = (a*a)%MOD
        b = b/2
    
    return result

while(t>0):
    s = sys.stdin.readline().split(' ')
    a = int(s[0])
    b = int(s[1])
    a %= MOD
    print expo(a,b)
    t-=1
