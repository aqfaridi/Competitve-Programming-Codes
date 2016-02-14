import random
t = 100
print 102
print "qwertyui"
print "mnbvcxzasdfgh"
for i in range(0,t):
    s = "abcdefghijklmnopqrstuvwxyz"
    l = random.randint(2 , 50)
    ss = ""
    for i in range(0,l):
        a = random.randint(0, 25)
        ss = ss+s[a]
    print ss
        
