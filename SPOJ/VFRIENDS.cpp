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
int d[MAX],cumm[MAX];
void erdos_Gallai(int n)
{
    int minSum;
    forr(i,1,n+1)
    {
        minSum = 0;
        forr(j,i+1,n+1)
            minSum += min(d[j],i);
        if(cumm[i] > (i*(i-1) + minSum))
        {
            cout<<"SAD"<<endl;
            goto down;
        }
    }
    cout<<"HAPPY"<<endl;
    
    down:;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=n;i>=1;i--)
            cin>>d[i];
        cumm[0] = 0;
        forr(i,1,n+1)
            cumm[i] = cumm[i-1] + d[i];
        if((cumm[n]&1)){ cout<<"SAD"<<endl; continue; }

        erdos_Gallai(n);
    }
    return 0; 
}
