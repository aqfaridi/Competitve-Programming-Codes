import sys
import math
while(1):
    n = sys.stdin.readline()
    if(len(n)==0):
        break
    n = int(n)
    n = float(n)
    #print n
    cnt = 0
    SQR = math.floor(math.sqrt(n))
    b = SQR
    while(b>=0):
        a = math.floor(math.sqrt( n - b*b ))
        if(a>b):
            break
        if(a*a + b*b == n):
            cnt += 1
        b -= 1
    print cnt
