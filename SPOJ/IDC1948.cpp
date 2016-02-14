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

#define MAX 10000
#define MOD 1000000007    
int sieve[MAX],primes[MAX],k;
void make_sieve()
{
    for(int i=2;i<=100;i++)
    {
        if(!sieve[i])
            for(int j=i*i;j<MAX;j+=i)
               sieve[j] = 1; 
    }
   
    for(int i=2;i<MAX;i++)
        if(!sieve[i])
            primes[k++] = i;
}
int main()
{
    make_sieve();
    ios::sync_with_stdio(false);
    int t,n,num,d;
    cin>>t;
    while(t--)
    {
        cin>>n;
        d = (int)log10(n) + 1;
        num = 0;
        for(int i=0;i<d;i++)
            num = num*10 + 9;

        num -= (2*n);
        if(num < 0) num = -num;

        if(num == 1 || num == -1)
        {
            cout<<-1<<endl;
            goto down;
        }
        int i;
        for(i=0;i<k;i++)
        {
            if(num%primes[i] == 0)
            {
                cout<<primes[i]<<endl;
                goto down;
            }
        }
        if(i == k)
            cout<<num<<endl;
        down:;
    }
    return 0;
}
