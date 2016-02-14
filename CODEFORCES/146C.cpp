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
#include <climits>
#include <cassert>

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
#define MOD 1073741824
int mark1[1000010];
int mark2[1000010];
int mark3[1000010];
void pf(int n)
{
    int N =n ;
    int cnt;
    for(int i=2;i*i<=n;i++)
        if(n%i == 0)
        {
            cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n/=i;
            }
            mark1[i] = 1;
        }
    if(n > 1)
        mark1[n] = 1;
    n = N-1;

    for(int i=2;i*i<=n;i++)
        if(n%i == 0)
        {
            cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n/=i;
            }
            mark2[i] = 1;
        }
    if(n > 1)
        mark2[n] = 1;
    
    n = N-2;   
    for(int i=2;i*i<=n;i++)
        if(n%i == 0)
        {
            cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n/=i;
            }
            mark3[i] = 1;
        }
    if(n > 1)
        mark3[n] = 1;
}
map<int,int> m;
void pf2(LL n)
{
    int cnt;
    for(int i=2;i*i<=n;i++)
        if(n%i == 0)
        {
            cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n/=i;
            }
            m[i] = max(m[i],cnt);
        }
    if(n > 1)
        m[n] = max(m[n],1);
}
LL expo(int a,int n)
{
    LL result= 1;
    while(n)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    LL n,ans,a,b,c,temp;
    cin>>n;

    if(n==1)
    {    cout<<1<<endl; return 0;}
    if(n==2)
    {   cout<<2<<endl; return 0;}
    if(n==3)
    {
        cout<<6<<endl; return 0;
    }
   
/*  for(int i=4;i<=n;i++)
   {
       m.clear();temp = 1;
       pf2(i);pf2(i-1);pf2(i-2);      
       map<int,int>::iterator it = m.begin();
       for(;it!=m.end();it++)
           temp = temp*expo(it->first,it->second);
       ans = max(ans,temp);
   }
   cout<<ans<<endl;
*/
    
    if((n&1)) {  ans = n*(n-1)*(n-2);   cout<<ans<<endl; return 0; }
    ans = 1;
    for(int i=max(1LL,n-50);i<=n;i++)
        for(int j=max(1LL,n-50);j<=n;j++)
            for(int k=max(1LL,n-50);k<=n;k++)
            {
                a = i;
                b = j;
                c = k;
                LL temp = a*b/__gcd(a,b);
                ans = max(ans,temp*c/__gcd(temp,c));
            }

    cout<<ans<<endl;
    

/*
    for(int i=500;i<=924;i++)
    {
        memset(mark1,0,sizeof(mark1));
        memset(mark2,0,sizeof(mark2));
        memset(mark3,0,sizeof(mark3));
        pf(i);
        cout<<i<<" = ";
        for(int j=1;j<=i;j++)
            if(mark1[j] && mark2[j] && mark3[j])
                cout<<j<<" ";
        cout<<endl;

    }
*/
    return 0; 
}
