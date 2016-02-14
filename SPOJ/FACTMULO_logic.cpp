#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
LL expo(LL a,LL n)
{
    LL result = 1;
    while(n)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}
LL str[100];
LL deci[100];
LL l,p;
void decimal()
{
    LL pwr = 1;
    LL result = 0;
    for(int i = 0 ; i < l ; i++)
    {
        result += pwr*(str[i]);        
        deci[i] = result;
        pwr *= p;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n,rem,ans,N,sum,p_i;
    cin>>t;
    while(t--)
    {
        cin>>p>>n;
        N = n;
        sum = (p*(p-1))/2;
        l = 0;
        while(n)
        {
            rem = n%p;
            str[l++] = (rem);
            n /= p;
        }
        decimal(); 
        ans = 0;
        for(int i=l-1;i>=0;i--)
        {
            rem = (str[i]);
            if(rem != 0)//ith bit set
            {
                 p_i = expo(p,i);
                 ans += ((p_i / p)*sum*i) * rem ;
                 n = deci[i];
                 ans += (n - rem*p_i + 1) * rem;
                 ans += (p_i)*(rem*(rem-1)/2);
            }
        }
        cout<<((N*(N+1)/2) - ans)/(p-1)<<endl;
        
    }
    return 0; 
}
