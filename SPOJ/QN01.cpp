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

#define MAX 1010
#define MOD 1000000007
int arr[MAX],xr[MAX];
int main()
{
    int t,n,maxx,pos_i,pos_j,xr_ij;
    scanf("%d",&n);
    forr(i,1,n+1)
        scanf("%d",&arr[i]);
    xr[0] = 0;
    xr[1] = arr[1];
    forr(i,2,n+1)
        xr[i] = xr[i-1]^arr[i];

    maxx = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            //i and j
            xr_ij = (xr[j]^xr[i-1]);
            if(xr_ij > maxx)
            {
                maxx = xr_ij;
                pos_i = i;
                pos_j = j;
            }
        }
    }
    printf("%d\n",maxx);
    printf("%d %d\n",pos_i,pos_j);
    return 0; 
}
