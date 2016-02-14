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

#define MAX 100010
#define MOD 1000000007

int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n,odd,even,ones;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ones = __builtin_popcountll(n);
        odd = (1LL << ones);
        even = n+1 - odd;
        cout<<even<<" "<<odd<<endl;
    }
    return  0;
}


