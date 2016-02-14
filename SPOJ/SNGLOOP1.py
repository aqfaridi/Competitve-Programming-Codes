t = input()
def expo(a,n):
    result = 1
    while(n):
        if(n%2 == 1):
            result = (result*a)%10
        a = (a*a)%10
        n /= 2
    return result%10
        
while(t>0):
    n,m = map(int,raw_input().split())    
    p = expo(3,m-n)
    print p        
    t -= 1

