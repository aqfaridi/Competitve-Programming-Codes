import sys
def expo(a,n,p):
    result = 1
    while(n>0):
        if((n&1)):
            result = (result*a)%p
        a = (a*a)%p
        n >>= 1
    return result%p
fact = [1]
def factorial(n):
    for i in range(1,n):
        fact.append(fact[i-1] * i);

#factorial(1000001)

for k in sys.stdin.readline():
    print k
    p = sys.stdin.readline()
    print p
    if(k>=p):
        print 0
        continue;
    neg = 1
    if((k&1)):
        neg = -1
    pro = p + neg*((fact[k-1]%p))    
    ans = expo(pro,p-2,p)
    print ans

