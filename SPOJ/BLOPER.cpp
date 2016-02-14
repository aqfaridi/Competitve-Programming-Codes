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
int track[550];
void track_back(int n,int N,int s,bool f)
{
    int s1 = (N-s)/2,sum,ptr;
    if(f)
        s1 += s;
    sum = 1;
    ptr = n;
    while(sum != s1 && ptr>1)
    {
        if(s1-sum >= ptr)
        {
            sum += ptr;
            track[ptr] = 1;
        }
        ptr--;
    }
    if(s1 != sum)
        printf("Impossible\n");
    else
    {
        printf("1");
        for(int i=2;i<=n;i++)
            (track[i]==1) ? printf("+%d",i) : printf("-%d",i);
        printf("\n");
    }
}
int main()
{
    int t,n,s,N;
    t = 1;
    while(t--)
    {
        scanf("%d %d",&n,&s);
        N = (n*(n+1))/2;
        if(s>=0)
        {
            if(((N-s)&1) || s>N)
            {
                printf("Impossible");
                continue;
            }
            track_back(n,N,s,1);
        }
        else
        {
            s = -s;
            if(((N-s)&1) || s > N)
            {
                printf("Impossible");
                continue;
            }
            track_back(n,N,s,0);
        }
    }
    return 0; 
}
