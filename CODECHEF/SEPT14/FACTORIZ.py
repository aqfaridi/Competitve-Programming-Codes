import math
MAX = 1000010
sieve = MAX*[0]
primes = []
def make_sieve():
    sieve[0] = sieve[1] = 1
    for i in range(2,int(math.sqrt(MAX))):
        if(sieve[i] == 0):
            for j in range(i*i,MAX,i):
                sieve[j] = 1
    for i in range(2,MAX):
        if(sieve[i] == 0):
            primes.append(i)
    
    #for i in range(0,100):
    #    print primes[i],

make_sieve()
t = input()
while(t>0):
    lst = []
    n = input()
    for i in range(0,1000):
        if(n%primes[i] == 0):
            while(n%primes[i] == 0):
                n/=primes[i]
                lst.append(primes[i])
    if(n>1):
        lst.append(n)
    l = len(lst)
    print l
    for i in lst:
        print i
    t -= 1
