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
#define MAX 200010
#define MOD 1000000007
set< pii > adjList[MAX];
int n;
namespace genLCA{
	const int LOGN = log2(MAX) + 1;
	int level[MAX],dist[MAX];
	int DP[LOGN][MAX]; // DP[i][j] : store (2^i)th parent of jth node
	void init_dfs(int u,int p){
		for(auto it=adjList[u].begin();it != adjList[u].end();it++){
			int v = (*it).X , w = (*it).Y;
			if(v != p){
				DP[0][v] = u; // parent of *it(child)
				level[v] = level[u] + 1;
				dist[v] = dist[u] + w;
				init_dfs(v,u);
			}
		}
	}

	void preprocess(){
		level[0] = DP[0][0] = dist[0] = 0;
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

	int find_dist(int a,int b){
		return dist[a] + dist[b] - 2*dist[lca(a,b)];
	}
}
using namespace genLCA;

namespace CentroidDecomposition {
	int sub[MAX],parent[MAX],flag[MAX],nonodes;
	multiset<int> mindist[MAX];
	set< pii > ctree[MAX];
	int subtree(int u,int p){
		nonodes++;
		sub[u] = 1;
		for(auto it=adjList[u].begin();it != adjList[u].end();it++){
			int child = (*it).X;
			if(child != p)
				sub[u] += subtree(child,u);
		}
		return sub[u];
	}
	int centroid(int u,int p){
		for(auto it=adjList[u].begin();it != adjList[u].end();it++){
			int child = (*it).X;
			if(child != p && sub[child] > nonodes/2)
				return centroid(child,u);
		}
		return u;
	}
	void decompose(int root,int p)
	{
		nonodes = 0;
		subtree(root,root);
		int c = centroid(root,root);
		if(p == -1) p = c;
		parent[c] = p; // centroid tree
		//ctree[c]
		for(auto it=adjList[c].begin();it != adjList[c].end();it++){
			int child = (*it).X;
			adjList[child].erase((*it));
			decompose(child,c);
		}
		adjList[c].clear();
	}

	void update(int u){
		int x = u;
		while(1){
			if(flag[u] == 1)
				mindist[x].insert(find_dist(u,x));
			else
				mindist[x].erase(find_dist(u,x));
			if(x == parent[x])	break;
			x = parent[x];
		}
	}

	int query(int u){
		int x = u;
		int minn = (1<<20);
		while(1){
			if(mindist[x].size() > 0)
				minn = min(minn,dist(u,x) + *mindist[x].begin());
			if(x == parent[x])	break;
			x = parent[x];
		}
		return minn;	
	}
}

using namespace CentroidDecomposition;

int main()
{_
	int u,v,w,q;
	char type;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>u>>v>>w;
		u -= 1; v -= 1;
		adjList[u].insert(mp(v,w));
		adjList[v].insert(mp(u,w));
	}

	preprocess();
	decompose(0,-1);

	for(int i=0;i<n;i++){
		flag[i] = 1;
		update(i);
	}
	int cnt = 0;

	cin>>q;
	while(q--){
		cin>>type;
		if(type == 'C'){
			cin>>u;
			u -= 1;
			flag[u] = 1 - flag[u];

			if(flag[u] == 1) cnt++;
			else cnt--;

			update(u);
		}
		else{
			if(cnt == 0)
				cout<<-1<<endl;
			else
				cout<<query(u)<<endl;
		}
	}
	return 0; 
}
