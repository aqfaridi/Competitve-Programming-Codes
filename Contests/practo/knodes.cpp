#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<assert.h>
#include<utility>
using namespace std;
typedef long long int ll;

#define mp	make_pair
#define pb push_back
#define MaxN 100009

vector<int> graph[MaxN];

/*************LCA Part is Here****************/
int Root[MaxN][18],log2[MaxN],depth[MaxN],start[MaxN],end[MaxN],parent[MaxN],counter,visited[MaxN];
void init()
{
	log2[0]=0;log2[1]=0;log2[2]=1;
	int cmp=4;
	for(int i=3;i<=100000;i++){
		if(cmp>i) log2[i]=log2[i-1];
		else{
			log2[i]=log2[i-1]+1;
			cmp<<=1;
		}
	}
}
void get2p(int N)
{
	memset(Root,-1,sizeof(int)*18*(N+1));
	for(int i=1;i<=N;i++)
		Root[i][0]=parent[i];
	for(int i=1;(1<<i)<=N;i++)
		for(int j=1;j<=N;j++)
			if(Root[j][i-1]!=-1)
				Root[j][i]=Root[Root[j][i-1]][i-1];
}
int lca(int p,int q)
{
	int temp;
	//first we make q the more deeper node
	if(depth[p]>depth[q])
		swap(p,q);
	//we find the closest power of 2
	int steps=log2[depth[q]];
	//we try to make the depth of q equal to p and then increase both
	for(int i=steps;i>=0;i--)
		if((depth[q]-(1<<i)) >= depth[p])
			q=Root[q][i];
	//if p was equal to q at the time of depth balancing then it is indeed a ancestor
	if(p==q)
		return p;
	//now we increase both p and q by small amount and if value is different , then we procede up
	for(int i=steps;i>=0;i--){
		if(Root[p][i]!=Root[q][i])
			p=Root[p][i],q=Root[q][i];
	}
	//we end up getting 1 node short for parent.
	return parent[p];
}
void LCA(int N)
{
	//if you have parent and depth stored
	get2p(N);
}
/*************************LCA part Ends********************/

void dfs(int root)
{
	visited[root] = 1;
	counter++;
	for(int i=0;i<graph[root].size();i++){
		int v = graph[root][i];
		if( visited[v] )	continue;
		else{
			depth[v] = depth[root] + 1;
			parent[v] = root;
			start[v] = counter;
			dfs(v);
		}
	}
	end[root] = counter;
}


void solve()
{
	int N;
	char tst;
	scanf("%d",&N);

	for(int i=1;i<=N;i++)	graph[i].clear(),visited[i] = 0;
	for(int i=1;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		graph[x].pb(y);
		graph[y].pb(x);
	}
	counter = 0;
	depth[1] = 1;
	parent[1] = -1;
	dfs(1);
	LCA(N);
	int Q,k,max_depth_node,max_d,smallest_depth_node,small_d;
	scanf("%d",&Q);
	//printf("%d is Q\n",Q);
	for(int i=1;i<=Q;i++){
		max_d = 0;
		small_d = 1e9;
		vector<int> nodes;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			if( depth[x] > max_d ){
				max_d = depth[x];
				max_depth_node = x;
			}
			if( depth[x] < small_d ){
				small_d = depth[x];
				smallest_depth_node = x;
			}
			nodes.pb(x);
		}
		//printf("%d %d %d %d\n",max_depth_node,max_d,smallest_depth_node,small_d);
		int diff = -1,flag=1,remaining_maximum_depth_node,rem_max_d=0;
		for(int j=0;j<k;j++){
			int u = nodes[j];
			if( start[u]<=start[max_depth_node] && end[u]>=end[max_depth_node] ){
				continue;
			}
			else{
				flag = 0;
				if( depth[u] > rem_max_d){
					rem_max_d = depth[u];
					remaining_maximum_depth_node = u;
				}
			}
		}

		if( flag ){
			printf("Yes\n");
			continue;
		}

		int print = 0;
		for(int j=0;j<k;j++){
			int u = nodes[j];
			if( start[u]<=start[max_depth_node] && end[u]>=end[max_depth_node] ){
				continue;
			}
			else if( !(start[u]<=start[remaining_maximum_depth_node] && end[u]>=end[remaining_maximum_depth_node]) ){
				printf("No\n");
				print = 1;
				break;
			}
		}
		if( print == 0 ){
			int x = lca(max_depth_node,remaining_maximum_depth_node);
			if( start[smallest_depth_node] >= start[x] && end[smallest_depth_node] <= end[x] ){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
	}
}

int main()
{
	init();
	char tst;
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}


