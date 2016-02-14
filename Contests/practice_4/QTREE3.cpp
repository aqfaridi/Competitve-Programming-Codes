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
#define INF (1<<30)
namespace heavyLightDecomposition{
    vector<int> adj[MAX]; // adj[u][v] edge, cost[u][i] edge cost , idx[u][i] ith edge
    int color[MAX],depth[MAX],parent[MAX],subsize[MAX],baseArray[MAX],chainIdx[MAX],chainHead[MAX],posInBase[MAX],chainNo,ptr;
    /**************Segment Tree Begins***********/
    int tree[4*MAX];
    int combine_int(int left,int right)
    {
        return min(left,right);
    }
    void init_tree(int node,int b,int e)
    {
        if(b==e) // leaf node
        {
            tree[node] = INF;
            return;
        }
        int mid = (b+e)/2;
        init_tree(2*node+1,b,mid);
        init_tree(2*node+2,mid+1,e);
        tree[node] = combine_int(tree[2*node+1],tree[2*node+2]);
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
            update(2*node+1,b,mid,index,newval);
        else
            update(2*node+2,mid+1,e,index,newval);

        tree[node] = combine_int(tree[2*node+1],tree[2*node+2]);
    }
    int query(int node,int b,int e,int i,int j)    
    {
        if(b>=i &&  e<=j)//in range   
            return tree[node];
        int mid = (b+e)/2;
        if(j<=mid)
            return query(2*node+1,b,mid,i,j);
        else if(i>mid)
            return query(2*node+2,mid+1,e,i,j);
        int p1 = query(2*node+1,b,mid,i,j);
        int p2 = query(2*node+2,mid+1,e,i,j);
        
        return combine_int(p1,p2);
    }
    /**************Segment Tree Ends*******************/

    /****************** LCA part Begins*****************/

    int DP[20][MAX],n; // Parent of Parent DP
    const int LOGN = 20;

    void preprocess(){
        depth[0] = DP[0][0] = 0;
        for(int i=0;i<n;i++)
            DP[0][i] = parent[i];
        for(int i=1;i<LOGN;i++)
            for(int j=0;j<n;j++)
                DP[i][j] = DP[i-1][DP[i-1][j]];
    }

    int query_lca(int a,int b){
        if(depth[a] > depth[b]) swap(a,b);
        int diff = depth[b] - depth[a];
        for(int i=0;i<LOGN;i++)
            if((diff & (1<<i)))
                b = DP[i][b];
        if(a == b)  return a;
        for(int i=LOGN-1;i>=0;i--)
            if(DP[i][a] != DP[i][b]) // different (2^i)th parent 
                a = DP[i][a],b = DP[i][b];
        return DP[0][a]; // parent of a
    }   
    /****************** LCA part Ends*****************/


    void dfs(int cur,int prev,int d=0)
    {
        parent[cur] = prev;
        depth[cur] = d;
        subsize[cur] = 1;
        for(int i=0;i < adj[cur].size();i++)
        {
            if(adj[cur][i] != prev)
            {
                dfs(adj[cur][i],cur,d+1);
                subsize[cur] += subsize[adj[cur][i]];
            }
        }
    }
    void HLD(int cur,int prev)
    {
        if(chainHead[chainNo] == -1)
            chainHead[chainNo] = cur;  // init chainHead of chainNo.
        
        ptr++;
        chainIdx[cur] = chainNo; //chainNo. of this node
        posInBase[cur] = ptr;  // Position of this node in baseArray
        baseArray[ptr] = cur;    // all nodes colored white initially in baseArray of SegTree 

        int sc = -1;
        for(int i=0;i<adj[cur].size();i++)
        {
            if(adj[cur][i] != prev)//dont compare with parent
            {
                if(sc == -1 || subsize[sc] < subsize[adj[cur][i]])
                    sc = adj[cur][i];  // max subsize child
            }
        }
        if(sc != -1) // not leaf node
            HLD(sc,cur);
            
        for(int i=0;i<adj[cur].size();i++)
        {
            if(adj[cur][i] != prev)
            {
                if(sc != adj[cur][i]) //all normal child
                {
                    //new chain for normal child
                    chainNo++;
                    HLD(adj[cur][i],cur);
                }
            }
        }
    }
    int query_up(int u,int v)
    {
        //if(u == v)  return 0;   //trivial
        int uchain = chainIdx[u];
        int vchain = chainIdx[v];
        int ans = INF,ret;
        while(1)
        {
            uchain = chainIdx[u];
            if(uchain == vchain)
            {
                //  if(u==v) break;
                ret = query(0,0,ptr,posInBase[v],posInBase[u]);  //v is ancestor
                ans = min(ans,ret);
                break;
            }
            ret = query(0,0,ptr,posInBase[chainHead[uchain]],posInBase[u]);
            ans = min(ans,ret);
            u = chainHead[uchain];
            u = parent[u];
        }
        return ans;
    }

    void query_solve(int u,int v)
    {
        
        int lca = 0;//query_lca(u,v);
        int ans = query_up(v,lca);
        if(ans != INF)
            cout<<baseArray[ans]+1<<endl;
        else
            cout<<-1<<endl;
    }

    void reset(int n)
    {
        ptr = -1;
        chainNo = 1;
        for(int i=0;i<=n;i++)
        {
            adj[i].clear();    
            parent[i] = -1;
            chainHead[i] = -1;
            color[i] = 1;
        }
    }
}
using namespace heavyLightDecomposition;
int main()
{_
    int t,u,v,c,a,b,q;
    string str;
    t = 1;
    while(t--)
    {
        cin>>n>>q;     
        reset(n);
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            u -= 1 , v -= 1;
            adj[u].pb(v);
            adj[v].pb(u); 
        }
        dfs(0,-1);//set subsize,depth,parent
        HLD(0,-1);//create BaseArray
        init_tree(0,0,ptr);
        //preprocess();
        while(q--)
        {
            cin>>a>>b;
            b -= 1;
            if(a)
                query_solve(1,b);
            else{
                color[b] = 1 - color[b];                
                if(color[b] == 0)  
                    update(0,0,ptr,posInBase[b],posInBase[b]);
                else
                    update(0,0,ptr,posInBase[b],INF);  
            }
        }
    }
    return 0; 
}
