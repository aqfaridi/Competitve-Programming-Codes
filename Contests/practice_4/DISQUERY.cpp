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
vector< pii > adjList[MAX];
int n;
namespace genLCA{
	const int LOGN = 20;
	int level[MAX],dst[MAX],maxx,minn;
	int DP[LOGN][MAX]; // DP[i][j] : store (2^i)th parent of jth node
	pii ST[LOGN][MAX]; // ST[i][j] : store max & min upto (2^i) length up of jth node
	void init_dfs(int u,int p){
		for(auto it=adjList[u].begin();it != adjList[u].end();it++){
			int v = (*it).X , w = (*it).Y;
			if(v != p){
				DP[0][v] = u; // parent of *it(child)
				dst[v] = dst[u] + w;
				ST[0][v].X = ST[0][v].Y = w;
				level[v] = level[u] + 1;
				init_dfs(v,u);
			}
		}
	}

	void preprocess(){
		level[0] = DP[0][0] = 0;
		ST[0][0].X = ST[0][0].Y = 0;
		init_dfs(0,0);
		for(int i=1;i<LOGN;i++)
			for(int j=0;j<n;j++){
				DP[i][j] = DP[i-1][DP[i-1][j]];
				ST[i][j].X = max(ST[i-1][j].X,ST[i-1][DP[i-1][j]].X);
				ST[i][j].Y = min(ST[i-1][j].Y,ST[i-1][DP[i-1][j]].Y);	
			}
	}

	int lca(int a,int b){
		if(level[a] > level[b]) swap(a,b);
		int diff = level[b] - level[a];
		for(int i=0;i<LOGN;i++)
			if((diff & (1<<i))){
				maxx = max(maxx,ST[i][b].X);
				minn = min(minn,ST[i][b].Y);
				b = DP[i][b];
			}
		if(a == b)	return a;
		for(int i=LOGN-1;i>=0;i--)
			if(DP[i][a] != DP[i][b]){ // different (2^i)th parent 
				maxx = max(maxx,max(ST[i][b].X,ST[i][a].X));
				minn = min(minn,min(ST[i][b].Y,ST[i][a].Y));
				a = DP[i][a],b = DP[i][b];
			}
		maxx = max(maxx,max(ST[0][b].X,ST[0][a].X));
		minn = min(minn,min(ST[0][b].Y,ST[0][a].Y));
		return DP[0][a]; // parent of a
	}	

	int dist(int a,int b){
		return dst[a] + dst[b] - 2*dst[lca(a,b)];
	}
}
using namespace genLCA;
int main()
{_
	int q,u,v,w;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>u>>v>>w;
		u -= 1 , v -= 1;
		adjList[u].pb(mp(v,w));
		adjList[v].pb(mp(u,w));
	}
	preprocess();
	cin>>q;
	while(q--){
		cin>>u>>v;
		u -= 1 , v -= 1;
		maxx = 0 , minn = (1<<20);
		int LCA = lca(u,v); //calc max & min value road internally using STable
		cout<<minn<<" "<<maxx<<endl;

	}
	return 0; 
}
