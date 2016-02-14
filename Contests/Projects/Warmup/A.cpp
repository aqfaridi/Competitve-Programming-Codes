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
typedef pair<int,pair<int,int> > tri;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector< pii > vpii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define fore(i,a,b)                 for(int i=a;i<=b;i++)
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
int a[110],b[110];

bool isoverlap(int a,int b,int c,int d){
    int minn = min(a,c);
    int maxx = max(b,d);
    
    int total = (b-a+1) + (d-c+1);
    if((maxx - minn + 1) < total)
        return true;
    else
        return false;
}

int main(){
	ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        rep(i,n)
            cin>>a[i];
        rep(i,n)
            cin>>b[i];
            
        int cnt = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(isoverlap(a[i],b[i],a[j],b[j]))
                    cnt++;
            }
         cout<<cnt<<endl;
    }
    

	return 0;
}