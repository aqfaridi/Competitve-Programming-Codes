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
typedef pair< int, pii > tri;

typedef vector<int> array;
typedef vector<LL> array_LL;
typedef vector<vector<int> > matrix;
typedef vector<vector<LL> > matrix_LL;


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

#define endl '\n'
#define MAX 1010
#define MOD 1000000007
int arr[MAX][MAX];
int mat[MAX][MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n,c=0,cnt1,cnt2;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            if(arr[i][j])   c++;
        }
    
    bool flag = false;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            cnt1 = cnt2 = 0;

            for(int k=1;k<=m;k++)
                if(arr[k][j])   cnt1++;
            for(int k=1;k<=n;k++)
                if(arr[i][k])   cnt2++;
   
            if(arr[i][j] && cnt1 != m && cnt2 != n)
                flag = true;
            if(cnt1 + cnt2 == (n+m))
                mat[i][j] = 1;
        }

    int cnt = 0;
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)if(!mat[i][j]) cnt++;
    if(flag || (cnt == n*m & c != 0))
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }

    return 0; 
}

