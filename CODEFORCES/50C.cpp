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

#define MAX 1010
#define MOD 1000000007
LL L[MAX],R[MAX],n;
double p[MAX],mem[MAX][MAX];
double solve(int idx,int k) // worst case : k=100 , i.e all good one items
{
   if(k == 0)
       return 1;

   if(idx == n)
       return 0;

    double& res = mem[idx][k];
    if(res != -1)  return res;
    res = 0;

    res = p[idx] * solve(idx+1,k-1);
    res += (1.0 - p[idx]) * solve(idx+1,k);

    return res;

}
int main()
{
    LL k,goodnum;
    cin>>n;
    rep(i,n)
        cin>>L[i]>>R[i];
    cin>>k;
    
    //find prob. that item-i is good one.
    rep(i,n)
    {
        goodnum = 0;
        for(LL j=0,pwr = 1;j<=18;pwr*=10,j++)
            goodnum += max((min(R[i],2*pwr-1) - max(L[i],pwr) + 1) , 0LL);         
        p[i] = (1.0 * goodnum)/(R[i]-L[i]+1);   
    }

    rep(i,n+1) rep(j,n+1) mem[i][j] = -1;

    int req = ceil((k*n)/100.0);
    printf("%.15lf\n",solve(0,req));

    return 0; 
}
