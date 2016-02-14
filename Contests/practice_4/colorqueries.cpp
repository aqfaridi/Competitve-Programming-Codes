#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define X first
#define Y second
#define all(v)                      v.begin(),v.end()	
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
int n,m,x,y,d,q,ans;
int arr[110][110],vis[110][110];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
void dfs(int x,int y){
	if(x < 0 || x >= n || y < 0 || y >= m)	return;

	ans++;
	vis[x][y] = 1;
	for(int i=0;i<4;i++)
		if(!vis[x + dx[i]][y + dy[i]] && abs(arr[x + dx[i]][y + dy[i]] - arr[x][y]) <= d )
			dfs(x + dx[i] , y + dy[i]);
}
int main()
{_
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	while(q--){
		cin>>x>>y>>d;
		x -= 1; y -= 1;
		ans = 0;
		memset(vis,0,sizeof vis);
		dfs(x,y);
		cout<<ans<<endl;
	}

	return 0; 
}
