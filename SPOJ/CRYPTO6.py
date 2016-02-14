import sys
import math
import random
cases = 0
def modulo(a,n,m):
    result = 1
    while(n>0):
        if(n&1):
            result = (result*a)%m
        a = (a*a)%m
        n >>= 1
    return (result+m*m) % m;

def gcd(a,b):
    if(b==0):
        return a
    else:
        return gcd(b,a%b)

def millerRabin(m,n,iteration):
        for i in range(iteration):
                a = random.randint(1, n-1)
                x = modulo(a,m/2,n)

                while(x == 1):
                    m = m/2
                    x = modulo(a,m/2,n)    
                g = gcd(x-1,n)                
                if(g != 1 and g  != n):
                    return g
                
while(1):
    s = raw_input()
    l = len(s)
    cnt = 0
    for i in range(l):
        if(s[i] == ' '):
            cnt+=1
    if(cnt == l):
        continue
    cases += 1
    ss = s.split()
    n = int(ss[0])
    d = int(ss[1])
    e = int(ss[2])
    if(n == 0 and d == 0 and e == 0):
        break
    if(n<=0 or d <=0 or e <= 0):
        break

    p = millerRabin(e*d,n,10);
    q = n/p
    if(p>q):
        p,q = q,p            
    print("Case #%d: %d %d" % (cases,p,q))
