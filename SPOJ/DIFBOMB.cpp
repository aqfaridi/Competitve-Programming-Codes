#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;
#define MAX 1000010
#define MOD 1000000007

int primes[MAX];
void sieve()
{
    primes[0]=primes[1]=1;
    for(int i=2;i*i<=MAX;i++)
    {
        for(int j=i*i;j<=MAX;j+=i)
            primes[j] = 1;
    }
}
long long mulmod(long long a,long long b,long long m)
{
    long long result = 0 ;
    while(b>0)
    {
        if((b&1))
            result = (result + a)%m;
        
        a = (2*a)%m;
        b >>= 1; 
    }
    return result%m;
}
long long modulo(long long a,long long n,long long m)
{
    long long result = 1;
    while(n>0)
    {
        if((n&1))
            result = mulmod(result,a,m);
        
        a = mulmod(a,a,m);
        n>>=1;
    }
    return result%m;
}
bool miller_rabin(long long n,int iteration)
{
    if(n<2)
        return false;
    if(n!=2 && n%2==0)
        return false;
    long long d=n-1;
    while(d%2==0)
        d/=2;
    for(int i=0;i<iteration;i++)
    {
        long long a = (rand() % (n-1) + 1);  
        long long temp = d;  
        long long mod = modulo(a,d,n);
        while(mod!=1 && mod!=(n-1) && temp!=(n-1))
        {
            mod = mulmod(mod,mod,n); 
            temp *= 2;
        }
        if(mod!=(n-1) && temp%2==0)  
            return false;
    }
    return true;

}

int main()
{
    ios::sync_with_stdio(false);
    int t,cnt,A,B;bool flag;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>A>>B;
        for(LL n = A;n<=B;n++)
        {
            flag = false;
            if(miller_rabin(n,1))
            {
                LL SQR = sqrt(n);
                for(LL b=SQR;b>=0;b--)
                {
                    LL a = sqrt(n - b*b);
                    if(a>b)
                        break;
                    if(a*a + b*b == n)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
                cnt++;
        }
        cout<<cnt<<endl;                
    }
    return  0;
}
