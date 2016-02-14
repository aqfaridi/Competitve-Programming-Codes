int MOD = 1000000007;
int expo(int a,int n)
{
    int result = 1;
    while(n)
    {
        if(n&1)
            result = (result*a);
        a = (a*a);
        n >>= 1;   
    }
    return result;
}
int main()
{
    int t,p,n,e,others,checkpoints,rem_elements,contr,pwr,ans;
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {
        sscanf(Stdio.stdin->gets(),"%d %d",p,e);
        n = expo(p,e);
        pwr = p;
        ans = 0;
        while(pwr <= n)
        {
            checkpoints = n/pwr;
            rem_elements = n%pwr;            
            contr = pwr * (checkpoints*(checkpoints-1)/2);
            others = checkpoints*(rem_elements+1);
            ans += (contr+others);
            pwr *= p;
        }
        write(ans%MOD+"\n");
    }
    return 0;
}

