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

#define MAX 20010
#define MOD 1000000007
vector<int> v[MAX];
int main()
{
    int t,n,m,size,var,maxx,cnt;
    bool flag;
    scanf("%d %d",&n,&m);
    rep(i,m)
    {
        scanf("%d",&size);
        rep(j,size)
        {
            scanf("%d",&var);
            v[i].push_back(var);
        }
    }
    maxx = 0;
    for(int i=(1<<m)-1;i>=0;i--)
    {
        int check[MAX] = {0};
        cnt = 0;
        flag = true;
        for(int j=0;j<20;j++)
        {
            if(i & (1<<j))
            {
               size = v[j].size();
               rep(k,size)
               {
                    if(!check[v[j][k]])
                        check[v[j][k]] = 1;
                    else
                    {
                        flag = false;
                        break;
                    }
               }

               if(!flag)
                   break;
               cnt++;
            }
        }
        maxx = max(maxx,cnt);
        if(flag)
            break;
    }
    printf("%d\n",maxx);
    return 0; 
}
