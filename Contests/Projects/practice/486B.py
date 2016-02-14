n = input()
o = n//2
e = n//2
if((n&1)):
    o += 1
ans = e*(e+1) - o*o;
print ans
