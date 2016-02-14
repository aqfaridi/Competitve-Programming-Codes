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

#define MAX 1000010
#define MOD 1000000007
map<int,int> m1;
map<int,int>::iterator it;
void prime_factorize(int n)
{
    int cnt;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i == 0)
        {
            cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n/=i;
            }
            //trace2(i,cnt);
            if(m1[i] == cnt)
                m1[i] = 0;
            else
                m1[i] = max(m1[i],cnt);
        }
    }
    if(n>1)
    {
        if(m1[n] == 1)
            m1[n] = 0;
        else
            m1[n] = max(m1[n],1);
        //trace2(n,1);
    }
}
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
LL lcm(LL a,LL b)
{
    return (a*b/__gcd(a,b));
}
void brute_force(LL m,LL n)
{
    forr(k,1,MAX)
    {
        if(lcm(m,k)%n == 0 && lcm(n,k)%m == 0)
        {
            cerr << k << endl;
            break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m;
    LL pro;
    cin>>t;
    while(t--)
    {
        m1.clear();        
        cin>>m>>n;
        //brute_force(m,n);
        prime_factorize(m);
        prime_factorize(n);
        pro = 1;
        for(it = m1.begin();it!=m1.end();it++)
            pro *= expo(it->first,it->second);
        cout<<pro<<endl;
        
    }
    return 0; 
}
