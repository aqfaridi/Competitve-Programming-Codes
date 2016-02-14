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
    int t,n,ans,f;
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {
        sscanf(Stdio.stdin->gets(),"%d",n);
        for(int i=1;i<=n;i++)
        {
            f = 1;
            for(int j=1;j<=i;j++)
                f = (f*fact[j])%n; 
            if(f == 0)
            {
                write("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
