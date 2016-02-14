import sys,math
dict = {}
dict[0] = 0
f = [0]*6
ar = [2,3,5]
def dicsum(i):        
        I = i
        I1 = i+1
        I2 = 2*i+1;
        for j in range(3):        
            if(i%ar[j] == 0):
                I = I/ar[j]
                f[ar[j]] = 1
        
            elif((i+1)%ar[j] == 0):
                I1 = I1/ar[j]
                f[ar[j]] = 1
        
            elif((2*i+1)%ar[j] == 0):
                I2 = I2/ar[j]
                f[ar[j]] = 1        
        
        x = 0
        pro = 1
        for j in range(2,6):
            if(j == ar[x]):
                if(f[ar[x]] == 0):
                    pro *= ar[x]
                x += 1;
        
        I4 = (3*i*i + 3*i - 1)/pro
        
        dict[i] = I*I1*I2*I4


def psum(prev,idx):
    if(idx not in dict):
        dicsum(idx)
    if(prev not in dict):
        dicsum(prev)

    return (dict[idx] - dict[prev] + m)%m

t = int(sys.stdin.readline())
while(t>0):
    s = sys.stdin.readline().split()
    n = int(s[0])
    m = int(s[1])
    prev = int(math.sqrt(n))
    ans = 0
    for i in range(int(math.sqrt(n)),0,-1):
        idx = n//i
        ans = (ans + ((i*i)%m*((i*i)%m*idx)%m)%m + (i*psum(prev,idx))%m)%m
        prev = idx
    print ans
    t -= 1
