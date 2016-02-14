#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

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

#define MAX 10010
#define MOD 1000000007
vector<int> adj[MAX],cost[MAX],idx[MAX];
int depth[MAX],parent[MAX],subsize[MAX],baseArray[MAX],chainIdx[MAX],chainHead[MAX],posInBase[MAX],otherEnd[MAX],chainNo,ptr;
namespace segmentTree
{
    int tree[3*MAX];
    void init_tree(int node,int b,int e)
    {
        if(b==e) // leaf node
        {
            tree[node] = baseArray[b];
            return ;
        }
        int mid = (b+e)/2;
        init_tree(2*node,b,mid);
        init_tree(2*node+1,mid+1,e);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
    void update(int node,int b,int e,int index,int newval)
    {
        if(b==e)
        {
            tree[node] = newval;
            return ;
        }

        int mid = (b+e)/2;
        if(index<=mid)
            update(2*node,b,mid,index,newval);
        else
            update(2*node+1,mid+1,e,index,newval);

        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
    int query(int node,int b,int e,int i,int j)    
    {
        if(b>=i &&  e<=j)//in range   
            return tree[node];
        int mid = (b+e)/2;
        if(j<=mid)
            return query(2*node,b,mid,i,j);
        else if(i>mid)
            return query(2*node+1,mid+1,e,i,j);
        int p1 = query(2*node,b,mid,i,j);
        int p2 = query(2*node+1,mid+1,e,i,j);
        
        return max(p1,p2);
    }
}
using namespace segmentTree;
void dfs(int cur,int prev,int d=0)
{
    parent[cur] = prev;
    depth[cur] = d;
    subsize[cur] = 1;
    for(int i=0;i < adj[cur].size();i++)
    {
        if(adj[cur][i] != prev)
        {
            otherEnd[idx[cur][i]] = adj[cur][i];
            dfs(adj[cur][i],cur,d+1);
            subsize[cur] += subsize[adj[cur][i]];
        }
    }
}
void HLD(int cur,int c,int prev)
{
    if(chainHead[chainNo] == -1)
        chainHead[chainNo] = cur;
    
    ptr++;
    chainIdx[cur] = chainNo;
    posInBase[cur] = ptr;
    baseArray[ptr] = c;

    int sc = -1,ncost;
    for(int i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i] != prev)//dont compare with parent
        {
            if(sc == -1 || subsize[sc] < subsize[adj[cur][i]])
            {
                sc = adj[cur][i];
                ncost = cost[cur][i];
            }
        }
    }
    if(sc != -1) // not leaf node
        HLD(sc,ncost,cur);
        
    for(int i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i] != prev)
        {
            if(sc != adj[cur][i]) //all normal child
            {
                //new chain for normal child
                chainNo++;
                HLD(adj[cur][i],cost[cur][i],cur);
            }
        }
    }
}
int query_up(int u,int v)
{
    if(u == v)  return 0;   //trivial
    int uchain = chainIdx[u];
    int vchain = chainIdx[v];
    int ans = -1,ret;
    while(1)
    {
        uchain = chainIdx[u];
        if(uchain == vchain)
        {
            if(u == v)  break;
            ret = query(1,1,ptr,posInBase[v]+1,posInBase[u]);  //v is ancestor
            if(ret > ans)    ans = ret;
            break;
        }
        ret = query(1,1,ptr,posInBase[chainHead[uchain]],posInBase[u]);
        if(ret > ans)   ans = ret;
        u = chainHead[uchain];
        u = parent[u];
    }
    return ans;
}

int P[MAX][14],n;
void preProcess()
{
    for(int i=0;i<=n;i++)
        for(int j=0;1<<j <= n;j++)
            P[i][j] = -1;
    for(int i=0;i<=n;i++)
        P[i][0] = parent[i];
    for(int j=1;1<<j < n;j++)
        for(int i=0;i<=n;i++)
            if(P[i][j-1] != -1)
                P[i][j] =  P[P[i][j-1]][j-1];
}
int query_lca(int p,int q)
{
    int lg;
    if(depth[p] < depth[q])
        swap(p,q);
    lg = log2(depth[p]);
    for(int i=lg;i>=0;i--)
        if(depth[p] - (1<<i) >= depth[q])
            p = P[p][i];

    if(p == q)
        return p;

    for(int i=lg;i>=0;i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i],q = P[q][i];
    return parent[p];
}
void query_solve(int u,int v)
{
    int lca = query_lca(u,v);
    int ans1 = query_up(u,lca);
    int ans2 = query_up(v,lca);
    printf("%d\n",max(ans1,ans2));
}
void change(int i, int val)
{
    int u = otherEnd[i];
    update(1,1,ptr,posInBase[u],val);
}
void reset(int n)
{
    ptr = 0;
    chainNo = 1;
    for(int i=0;i<=n;i++)
    {
        adj[i].clear();    
        cost[i].clear();
        idx[i].clear();    
        parent[i] = -1;
        chainHead[i] = -1;
    }
}
int main()
{
    int t,u,v,c,a,b;
    char str[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);      
        reset(n);
        for(int i=1;i<n;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            adj[u].pb(v);
            cost[u].pb(c);
            idx[u].pb(i);//ith edge
            adj[v].pb(u);
            cost[v].pb(c);
            idx[v].pb(i);
        }
        dfs(1,-1);//set subsize,depth,parent
        HLD(1,-1,-1);//create BaseArray
        init_tree(1,1,ptr);
        preProcess();
        while(1)
        {
            scanf("%s",str);
            if(str[0] == 'D')
                break;
            scanf("%d %d",&a,&b);
            if(str[0] == 'Q')
                query_solve(a,b);
            else 
                change(a,b);
        }
    }
    return 0; 
}
