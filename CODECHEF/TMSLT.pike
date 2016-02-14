#define MAX 3000010
#define MOD 1000000
array(int) S = ({});
void precompute(int n,int a,int b,int c,int d)
{
    S = allocate(n);
    S[0] = d;
    for(int i=1;i<n;i++)
        S[i] = ((a*S[i-1]*S[i-1]) + (b*S[i-1]) + c)%MOD;
}
int main()
{
    int t,n,a,b,c,d,odd,even; 
    sscanf(Stdio.stdin->gets(),"%d",t);
    while(t--)
    {
        sscanf(Stdio.stdin->gets(),"%d %d %d %d %d",n,a,b,c,d);
        precompute(n,a,b,c,d);
        sort(S);
        odd = even = 0;
        for(int i=0;i<n;i++)
        {
            if(i&1) 
                odd += S[i];
            else
                even += S[i];
        }
        write(abs(odd-even) + "\n");
    }
    return 0;
}
