int MOD = 1000000007;
int expo(int a,int n)
{
    int result = 1;
    while(n)
    {
        if(n&1)
            result = (result*a)%MOD;
        a = (a*a)%MOD;
        n >>= 1;   
    }
    return result%MOD;
}
int modInverse(int a,int b)

{
    //ax + by = gcd(a,b)
    //r(i) = r(i-2) - q(i)*r(i-1)
    int xLast = 1,yLast = 0,q,r,m,n;
    int x = 0,y = 1;
    while(b)
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

int main()
{
    int t,sum,p,e,X,exp,n,n2,Nr,Dr,p2;
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {

        sscanf(Stdio.stdin->gets(),"%d %d",p,e);
        // eth bit is set only
        exp = expo(p,e-1);
        n = (exp*p)%MOD;
        n2 = (n*n)%MOD;
        sum = (p*(p-1))/2;
        X = (1 + (exp*sum*e)%MOD)%MOD; 
        X = (2*X)%MOD;

        Nr = (n2 + n - X +2*MOD)%MOD;
        p2 = 2*(p-1);
        Dr = modInverse(p2,MOD);
        write("%d\n",(Nr*Dr)%MOD);
        
    }
    return 0; 
}
