#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MAX 1000010
int sieve[MAX];
int f_primes[]={3,5,17,257,65537};
void make_sieve()
{
    LL num,pro;
    for(int i=0;i<20;i++)
    {
       num = (1LL<<i);
       for(int j=0;j<=31;j++)
       {
            pro = 1;
            for(int k=0;k<=4;k++)
            {
                if((1LL<<k) & j)
                {
                    pro *= f_primes[k];
                }
            }
            if(num*pro > MAX) continue;
            sieve[num*pro] = 1;
       }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    make_sieve();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(sieve[n])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
