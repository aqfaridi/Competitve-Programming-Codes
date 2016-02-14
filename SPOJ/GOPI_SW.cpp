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
    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define debug                       if(1)
#define debugoff                    if(0)    

#define MAX 1000010
#define MOD 1000000007
vector<int> v;
int dp[10000];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,P,sqr,size,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int p=2;p<=42;p++)
        {
            v.clear();
            P = p;
            for(int i=2;i*i<p;i++)
            {
                if(P%i == 0)
                {
                    v.push_back(i);
                    v.push_back(p/i);
                }
            }  
            sqr = (int)sqrt(p);
            
            if(sqr * sqr == p)
                v.push_back(sqr);
            v.push_back(p);


            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
            size = v.sz;
            
            trace1(p);

            for(int i=0;i<size;i++)
                cout<<v[i]<<" ";
            cout<<endl;
            sum = p-1;
            memset(dp,0,sizeof(dp));
            dp[0] = 1;
            for(int i=0;i<size;i++)            
            {
                for(int j=sum;j>=v[i];j--)
                    dp[j] |= dp[j - v[i]];
            }
            
            if(dp[sum])
                cout<<p<<endl;
        }


    }
    return 0; 
}
