MOD = 1000000007
def expo(a,n):
    result = 1
    while(n>0):
        if((n&1)):
            result = (result*a)%MOD
        a = (a*a)%MOD
        n >>= 1
    return result%MOD
t = input()
while(t>0):
    try:
        s = raw_input()
        if(len(s) == 0):
            continue
        ss = s.split(' ')
        a = int(ss[0])
        n = int(ss[1])
        a %= MOD
        print expo(a,n)
    except :
        break
    t -= 1
