//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; si(t); while(t--)

#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(3e5);
const int LOGN = 22;
set<int> g[N];
int sub[N],par[N],dist[LOGN][N],level[N];
LL sum[N],cnt[N],ctbn[N];
int A[N],DP[LOGN][N],msb[N],Q[N];
void build(int l,int r,int p)
{
	if(l>r)return;
	int d = msb[r-l+1];
	int L = DP[d][l];
	int R = DP[d][r-(1<<d)+1];
	int mn = (A[L]<A[R]?L:R);
	if(p!=-1)g[p].insert(mn),g[mn].insert(p);
	build(l,mn-1,mn);
	build(mn+1,r,mn);
}
/*----------- Centroid Decomposition ------------*/
int nn;
void dfs1(int u,int p)
{
	sub[u]=1;nn++;
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
			dfs1(*it,u),sub[u]+=sub[*it];
}
int dfs2(int u,int p)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p && sub[*it]>nn/2)
			return dfs2(*it,u);
	return u;
}
void dfs3(int u,int p,int d)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
			dist[d][*it]=dist[d][u]+1,dfs3(*it,u,d);
}
void decompose(int root,int p)
{
	nn=0;
	dfs1(root,root);
	int centroid = dfs2(root,root);
	if(p==-1)p=centroid;
	else level[centroid]=level[p]+1;
	par[centroid]=p;
	dfs3(centroid,centroid,level[centroid]);
	for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
	{
		g[*it].erase(centroid);
		decompose(*it,centroid);
	}
}
int main()
{
	int n;si(n);
	for(int i=1;i<=n;i++)
	{
		si(Q[i]);
		A[Q[i]]=i;
	}
	//RMQ PRE-PROCESSING
	for(int i=1;i<=n;i++)
		DP[0][i]=i;
	for(int i=1;i<LOGN;i++)
		for(int j=1;j<=n;j++)
		{
			int l = DP[i-1][j], r=DP[i-1][min(n,j+(1<<(i-1)))];
			if(A[l]<A[r])
				DP[i][j] = l;
			else
				DP[i][j] = r;
		}
	for(int i=1,x=0;i<N;i++)
		if((1<<(x+1)<=i))
			msb[i]=(++x);
		else
			msb[i]=x;
	//BUILD THE TREE
	build(1,n,-1);	//O(N);
	//DECOMPOSE THE TREE
	decompose(1,-1);

	//HANDLE THE QUERIES
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		int x,u;
		x = u = Q[i];
		ans+=sum[x];
		while(x!=par[x])
		{
			LL d = dist[level[par[x]]][u];
			ans += sum[par[x]]-ctbn[x] + ((LL)cnt[par[x]]-cnt[x])*d;	
			ctbn[x] += d;cnt[x]++;sum[par[x]]+=d;
			x = par[x];
		}
		cnt[x]++;
		lldout(ans);
	}
	return 0;
}
