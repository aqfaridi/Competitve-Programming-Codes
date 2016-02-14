array(int) pwr = allocate(100);
array(int) str = allocate(100);
int l,p;
array(int) dec = allocate(100);
int decimal()
{
    int pwr = 1;
    int result = 0;
    for(int i = 0 ; i < l ; i++)
    {
        result += pwr * (str[i]);   
        dec[i] = result;     
        pwr *= p;
    }
    return result;
}
int main()
{
    int t;
    int n,rem,ans,N,sum,pp,res;
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {

        sscanf(Stdio.stdin->gets(),"%d %d",p,n);
        N = n;
        sum = (p*(p-1))/2;
        l = 0;
        while(n)
        {
            rem = n%p;
            str[l++] = rem;
            n /= p;
        }
        /*************Pre-Computation************/
        pwr[0] = 1;
        for(int i=1;i<l;i++)
            pwr[i] = pwr[i-1]*p;
        
    pp = 1;
    res = 0;
    for(int i = 0 ; i < l ; i++)
    {
        res += pp * (str[i]);   
        dec[i] = res;     
        pp *= p;
    }
        /****************************************/
        ans = 0;
        for(int i=l-1;i>=0;i--)
        {
            if(str[i] != 0)//ith bit set
            {
                 //ans += ((pwr[i] / p)*sum*i) * rem ;
                 n = dec[i];
                 ans += str[i]*(n+1) - pwr[i]*(str[i]*(str[i]+1)/2 - str[i]*(sum*i)/p);
                 //ans += (n - rem*pwr[i] + 1) * rem;
                 //ans += (pwr[i])*(rem*(rem-1)/2);
            }
        }
        //write(ans+"\n");
        //write(N*(N+1)/2 +"\n");

        write("%d\n",((N*(N+1)/2 - ans)/(p-1)));
        
    }
    return 0; 
}
