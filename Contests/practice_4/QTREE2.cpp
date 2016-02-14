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
int n,k;
namespace genLCA{
	const int LOGN = 20;
	int level[MAX],dst[MAX],maxx,minn;
	int DP[LOGN][MAX]; // DP[i][j] : store (2^i)th parent of jth node
	void init_dfs(int u,int p){
		for(auto it=adjList[u].begin();it != adjList[u].end();it++){
			int v = (*it).X , w = (*it).Y;
			if(v != p){
				DP[0][v] = u; // parent of *it(child)
				dst[v] = dst[u] + w;
				level[v] = level[u] + 1;
				init_dfs(v,u);
			}
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
		return dst[a] + dst[b] - 2*dst[lca(a,b)];
	}
}
using namespace genLCA;
void reset(){
	for(int i=0;i<n;i++)
		adjList[i].clear();
}
int main()
{_
	int q,u,v,w,t;
	string str;
	cin>>t;
	while(t--){
		cin>>n;
		reset();
		for(int i=0;i<n-1;i++){
			cin>>u>>v>>w;
			u -= 1 , v -= 1;
			adjList[u].pb(mp(v,w));
			adjList[v].pb(mp(u,w));
		}
		preprocess();
		while(1){
			cin>>str;
			if(str == "DONE")	break;

			if(str == "DIST"){
				cin>>u>>v;
				u -= 1 , v -= 1;
				cout<<dist(u,v)<<endl;
			}
			else{
				cin>>u>>v>>k;
				u -= 1 , v -= 1;
				int LCA = lca(u,v);
				int diff = level[u] - level[LCA] + 1;
				int d = diff + level[v] - level[LCA];
				if(diff < k){  // switch from other end v
					k = d-k+1; 
					u = v;
				}
				k -= 1;
				for(int i=0;i<LOGN;i++)
					if((k & (1<<i)))
						u = DP[i][u];
				cout<<u+1<<endl;
			}
		}
	}
	return 0; 
}
