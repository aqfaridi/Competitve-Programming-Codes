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
bool sieve[MAX];
void make_sieve()
{
    sieve[0] = sieve[1] = 1;
    for(int i=2;i*i<=MAX;i++)
    {
        if(!sieve[i])
            for(int j=i*i;j<=MAX;j+=i)
                sieve[j] = 1;
    }
}
bool devlali[MAX+100];
vector< int > dev;
void make_devlali()
{
    int sum,n;
    for(int i=0;i<=MAX;i++)
    {    
        n = i;
        sum = n;
        while(n)
        {
            sum += (n%10);
            n /= 10;
        }
        devlali[sum] = 1;
    }
   
    for(int i=0;i<MAX;i++)
    {
        if(!devlali[i] && !sieve[i])            
            dev.push_back(i);      
    }
}
int main()
{
    ios::sync_with_stdio(false);
    make_sieve();
    make_devlali();
    int t,A,B;
    cin>>t;
    while(t--)
    {
        cin>>A>>B;
        cout<<upper_bound(dev.begin(),dev.end(),B)-lower_bound(dev.begin(),dev.end(),A)<<endl;
    }
    return 0;
}
