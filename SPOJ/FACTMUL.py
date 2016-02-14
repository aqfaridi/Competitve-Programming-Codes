fact = [1]
res = [1]
MOD = 109546051211
n = input()
if(n>=587117):
    print 0
else:
    for i in range(1,n+1):
        fact.append( (i%MOD * fact[i-1]%MOD)%MOD )
        res.append( (res[i-1]%MOD * fact[i]%MOD)%MOD )
    
    print res[n]

