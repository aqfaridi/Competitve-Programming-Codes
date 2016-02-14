int modulo(int a,int n,int m)
{
    int result = 1;
    while(n>0)
    {
        if((n&1))
            result = (result*a)%m;
        
        a = (a*a)%m;
        n>>=1;
    }
    return result%m;
}

int expo(int a,int n)
{
    int result = 1;
    while(n>0)
    {
        if((n&1))
            result = (result*a);
        
        a = (a*a);
        n>>=1;
    }
    return result;
}
int rabin_miller(int n,int iteration)
{
    if(n<2)
        return false;
    if(n!=2 && n%2==0)
        return false;
    int d=n-1;
    while(d%2==0)
        d/=2;
    for(int i=0;i<iteration;i++)
    {
        int a = random(n-1) + 1; //a: 1 to n-1 
        int temp = d;   // for while stopping condition
        int mod = modulo(a,d,n);
        while(mod!=1 && mod!=(n-1) && temp!=(n-1))
        {
            mod = (mod*mod)%n; // squaring mod
            temp *= 2;
        }
        if(mod!=(n-1) && temp%2==0) 
             return expo(a,temp)-1;
    }
    return 1;
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int n,d,e,p,q,cases = 0,f,temp;
    float k,phi,a,b,c;
    while(1)
    {
        cases++;
        sscanf(Stdio.stdin->gets(),"%d %d %d",n,d,e);
        if(n==0 && d == 0 && e == 0)
            break;
        if(n==0)
        {
            write("Case #%d: %d %d\n",cases,0,0);
            continue;
        }

        k = ceil(d*e*1.0/n);
        phi = (d*e - 1)/k;

        a = 1.0;
        b = -1.0*(n+1-phi);
        c = n*1.0;
        if(b*b - 4.0*a*c < 0.0)
        {
            
            write("Case #%d: %d %d\n",cases,0,0);
            /*
            while(1)
            {
                f = rabin_miller(e*d,1);
                if(f != 1)
                {
                    p = gcd(f,n);
                    q = n/p;
                    if(p>q)
                    {
                        temp = p;
                        p = q;
                        q = temp;
                    }
                    if(p == 1 || p == n)
                        continue;
                    write("Case #%d: %d %d\n",cases,p,q);
                    break;
                }
            }
            */
            continue;
        }

        p = (int)((-b - sqrt(b*b - 4.0*a*c))/2.0);
        q = (int)((-b + sqrt(b*b - 4.0*a*c))/2.0);

        write("Case #%d: %d %d\n",cases,p,q);        
    }
    return 0;
}
