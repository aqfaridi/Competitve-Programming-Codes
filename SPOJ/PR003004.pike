array(int) pwr = allocate(100);
array(int) str = allocate(100);
int l,p=10,sum=45;
array(int) dec = allocate(100);
void power()
{
    pwr[0] = 1;
    for(int i=1;i<20;i++)
        pwr[i] = pwr[i-1]*p;
}
void decimal()
{
    int pwr = 1;
    int result = 0;
    for(int i = 0 ; i < l ; i++)
    {
        result += pwr * (str[i]);   
        dec[i] = result;     
        pwr *= p;
    }
}

int compute(int n)
{
    int rem;
    l = 0;
    while(n)
    {
        rem = n%10;
        str[l++] = rem;
        n/=10;
    }
    
    decimal();    
    int ans = 0;
    
    for(int i=l-1;i>=0;i--)
    {
        rem = str[i];
        if(rem != 0)//ith bit set
        {
             n = dec[i];
             ans += pwr[i-1]*sum*i*rem ;
             ans += (n - rem*pwr[i]+1)*rem;
             ans += (rem*(rem-1)/2)*pwr[i];
        }
    }

    return ans;
}

int main()
{
    int a,b,t;
    power();    
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {
        
        sscanf(Stdio.stdin->gets(),"%d %d",a,b);
        if(a == 0)
            a = 1;
        b = compute(b);
        a = compute(a-1);
        write("%d\n",(b - a));
        
    }
    return 0; 
}


