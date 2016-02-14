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
vector<int> adjList[MAX];
int n;
namespace genLCA{
	const int LOGN = 20;
	int level[MAX];
	int DP[LOGN][MAX]; // DP[i][j] : store (2^i)th parent of jth node
	void init_dfs(int u,int p){
		for(auto it=adjList[u].begin();it != adjList[u].end();it++)
			if(*it != p){
				DP[0][*it] = u; // parent of *it(child)
				level[*it] = level[u] + 1;
				init_dfs(*it,u);
			}
	}

	void preprocess(){
		level[0] = DP[0][0] = 0;
		init_dfs(0,0);
		for(int i=1;i<LOGN;i++)
			for(int j=0;j<n;j++)
				DP[i][j] = DP[i-1][DP[i-1][j]];
	}

	int lca(int a,int b){
		if(level[a] > level[b]) swap(a,b);
		int diff = level[b] - level[a];
		for(int i=0;i<LOGN;i++)
			if((diff & (1<<i)))
				b = DP[i][b];
		if(a == b)	return a;
		for(int i=LOGN-1;i>=0;i--)
			if(DP[i][a] != DP[i][b]) // different (2^i)th parent 
				a = DP[i][a],b = DP[i][b];
		return DP[0][a]; // parent of a
	}	

	int dist(int a,int b){
		return level[a] + level[b] - 2*level[lca(a,b)];
	}
}
using namespace genLCA;
int cnt[MAX];
void solve_post(int u,int p){
	for(auto it=adjList[u].begin();it != adjList[u].end();it++)
		if((*it) != p){
			solve_post(*it,u);
			cnt[u] += cnt[*it];
		}

}
int a[MAX],b[MAX];
int main()
{_
	int q,u,v;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		u -= 1 , v -= 1;
		a[i] = u ; b[i] = v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	preprocess();
	cin>>q;
	while(q--){
		cin>>u>>v;
		u -= 1 , v -= 1;
		cnt[u]++ , cnt[v]++;
		int LCA = lca(u,v);
		cnt[LCA] -= 2;
	}
	solve_post(0,0);
	for(int i=0;i<n-1;i++){
		u = a[i] , v = b[i];
		if(level[u] < level[v])	swap(u,v);
		cout<<cnt[u]<<" ";
	}
	return 0; 
}
