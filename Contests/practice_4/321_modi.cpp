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
int sub[MAX],parent[MAX],nonodes;
char ans[MAX];
void subtree(int u,int p){
	nonodes++;
	sub[u] = 1;
	for(auto it=adjList[u].begin();it != adjList[u].end();it++)
		if(*it != p){
			subtree(*it,u);
			sub[u] += sub[*it];
		}
}
int centroid(int u,int p){
	for(auto it=adjList[u].begin();it != adjList[u].end();it++)
		if(*it != p && sub[*it] > nonodes/2)
			return centroid(*it,u);
	return u;
}
void decompose(int root,int p,char ch)
{
	nonodes = 0;
	subtree(root,root);
	int c = centroid(root,root);
	if(p == -1) p = c;
	parent[c] = p; // centroid tree
	ans[c] = ch;
	for(auto it=adjList[c].begin();it != adjList[c].end();it++){
		adjList[*it].erase(c);
		decompose(*it,c,ch+1);
	}
	adjList[c].clear();
}
int main()
{_
	int n,u,v;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&u,&v);
		u -= 1; v -= 1;
		adjList[u].insert(v);
		adjList[v].insert(u);
	}

	decompose(0,-1,'A');
	for(int i=0;i<n;i++)
		printf("%c ",ans[i]);
	printf("\n");

	return 0; 
}
