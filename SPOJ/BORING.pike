int modInverse(int a,int b)

{
    //ax + by = gcd(a,b)
    //r(i) = r(i-2) - q(i)*r(i-1)
    int xLast = 1,yLast = 0,q,r,m,n;
    int x = 0,y = 1;
    while(b!=0)
    {
        q = a/b;
        r = a%b;
        m = xLast - q*x;
        n = yLast - q*y;
        xLast = x ; yLast = y;
        x = m ; y = n;
        a = b; b = r;
    }
    return xLast;
}

array(int) fact = allocate(10001);
void precompute()
{
    fact[0] = 1;
    for(int i=1;i<10001;i++)
        fact[i] = fact[i-1]*i;
}
int main()
{
    precompute();
    int t,n,p,neg,k,pro,ans;
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {
        sscanf(Stdio.stdin->gets(),"%d %d",n,p);
        if(n>=p)
        {
            write(0+"\n");
            continue;
        }
        
        neg = 1;
        k = p-n;
        if(k&1)
            neg = -1;
        pro = p + neg*(fact[k-1]%p);
        ans = (modInverse(pro,p) + p)%p;
        write("%d\n",ans);
    }
    return 0;
}
