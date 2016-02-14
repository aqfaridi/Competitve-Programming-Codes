#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define all(v)                      v.begin(),v.end()	
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
set<int> adjList[MAX];
int n;
namespace genLCA{
	const int LOGN = log2(MAX) + 1;
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

namespace CentroidDecomposition {
	int sub[MAX],parent[MAX],mindist[MAX],nonodes;
	int subtree(int u,int p){
		nonodes++;
		sub[u] = 1;
		for(auto it=adjList[u].begin();it != adjList[u].end();it++)
			if(*it != p)
				sub[u] += subtree(*it,u);
		return sub[u];
	}
	int centroid(int u,int p){
		for(auto it=adjList[u].begin();it != adjList[u].end();it++)
			if(*it != p && sub[*it] > nonodes/2)
				return centroid(*it,u);
		return u;
	}
	void decompose(int root,int p)
	{
		nonodes = 0;
		subtree(root,root);
		int c = centroid(root,root);
		if(p == -1) p = c;
		parent[c] = p; // centroid tree
		for(auto it=adjList[c].begin();it != adjList[c].end();it++){
			adjList[*it].erase(c);
			decompose(*it,c);
		}
		adjList[c].clear();
	}

	void update(int u){
		int x = u;
		while(1){
			mindist[x] = min(mindist[x],dist(u,x));
			if(x == parent[x])	break;
			x = parent[x];
		}
	}

	int query(int u){
		int x = u;
		int minn = (1<<20);
		while(1){
			minn = min(minn,dist(u,x) + mindist[x]);
			if(x == parent[x])	break;
			x = parent[x];
		}
		return minn;	
	}
}

using namespace CentroidDecomposition;

int main()
{_
	int u,v,q,type;
	cin>>n>>q;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		u -= 1; v -= 1;
		adjList[u].insert(v);
		adjList[v].insert(u);
	}
	preprocess();
	decompose(0,-1);
	for(int i=0;i<n;i++)
		mindist[i] = (1<<20);

	update(0);
	while(q--){
		cin>>type>>u;
		u -= 1;
		if(type == 1)
			update(u);
		else
			cout<<query(u)<<endl;
	}
	return 0; 
}
