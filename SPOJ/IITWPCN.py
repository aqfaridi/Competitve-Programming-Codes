import sys
t = input()
while(t):
    str = sys.stdin.readline().split()
    B = int(str[1])
    if(B&1):
        print "1.000000"
    else:
        print "0.000000"
    t -= 1


    

