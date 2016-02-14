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
int a[1010][1010];
void pre(){
    int t,n=800;
    for(int i=0;i<n;i++)    a[i][0] = a[i][i] = a[0][i] = 1;
    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++){
            for(int step=1;step<=max(i,j);step++){
                if((i-step >= 0) && (a[i-step][j] == 0)){
                        a[i][j] = 1;break;
                    }
                if((j-step >= 0) && (a[i][j-step] == 0)){
                        a[i][j] = 1;break;
                    }
                if((j-step >= 0) && (i-step >= 0) && (a[i-step][j-step] == 0)){
                        a[i][j] = 1;break;
                    }
            }   
        }
}
int solve(int i,int j){
    if(i == 0 || j==0 ||  i==j)  return 1;
    if(i < 800 && j < 800)
        return a[i][j];
        
    int res = 0;
    for(int step=1;step<=max(i,j);step++){
                if(i-step >= 0) res = res || solve(i-step,j);
                if(j-step >= 0) res = res || solve(i,j-step);
                if((j-step >= 0) && (i-step >= 0))
                    res = res || solve(i-step,j-step);
            }   
            
    return res;
}
#define endl '\n'
int main(){
    pre();
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t,n1,n2;
    cin>>t;
    while(t--){
        cin>>n1>>n2;
        if(solve(n1,n2))
            cout<<"Play"<<endl;
        else
            cout<<"Don't Play"<<endl;
    }
	return 0;
}