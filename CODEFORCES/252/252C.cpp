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
vector< pii > v;
int spiral[500][500];
int main()
{
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    
    int i=1,j=1,l=1,ur=n,uc=m;
    for(int num=1;num<=n*m;num++)
    {
        spiral[i][j] = num;
        v.pb(mp(i,j));
        if(i==l && j<uc)//right
            j++;
        else if(j==uc && i<ur)//down
            i++;
        else if(i==ur && j>l)//left
            j--;
        else if(j==l && i>l)//up
            i--;
    
        if(spiral[i][j] != 0)
            i++;j++;l++;ur--;uc--;
    }

    int idx = 0;
    for(int i=0;i<=(k-2);i++)
    {
        cout<<2<<" ";
        cout<<v[idx].first<<" "<<v[idx].second<<" ";
        idx++;
        cout<<v[idx].first<<" "<<v[idx].second<<endl;;
        idx++;
    }
    cout<<v.size()-idx<<" ";
    for(int i=idx;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<" ";

    return 0; 
}
