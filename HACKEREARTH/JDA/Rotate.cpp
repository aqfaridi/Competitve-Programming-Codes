#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 
#include <climits>
#include <cassert>

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

#define MAX 1000010
#define MOD 1000000007

namespace segmentTree
{
    struct data
    {
        int maxx,N,E,W,S;
    };
    data tree[3*MAX];
    int clock[3*MAX],anti[3*MAX];
    data combine_data(data left,data right)
    {
        data res;
        res.N = left.N + right.N;
        res.E = left.E + right.E;
        res.W = left.W + right.W;
        res.S = left.S + right.S;
        res.maxx = max(res.N,max(res.E,max(res.W,res.S)));
        return res;
    }
    data make_data(int val)
    {
        data res;
        res.E = res.maxx = val;
        res.N = res.W = res.S = 0;
        return res;
    }
    void init_tree(int node,int b,int e)
    {
        if(b==e) // leaf node
        {
            tree[node] = make_data(1);
            return ;
        }
        int mid = (b+e)/2;
        init_tree(2*node,b,mid);
        init_tree(2*node+1,mid+1,e);
        tree[node] = combine_data(tree[2*node],tree[2*node+1]);
    }
    void make_clock(int node,int k)
    {
        int rotate = k%4;
        int tN = tree[node].N,tE = tree[node].E,tW = tree[node].W,tS = tree[node].S;
     
        if(rotate == 1)
        {
            tree[node].E = tN ; tree[node].W = tS;
            tree[node].N = tW ; tree[node].S = tE;
        }
        if(rotate == 2)
        {
            tree[node].E = tW ; tree[node].W = tE;
            tree[node].N = tS ; tree[node].S = tN;
        }
        else if(rotate == 3)
        {
            tree[node].E = tS ; tree[node].W = tN;
            tree[node].N = tE ; tree[node].S = tW;
        }
    }

    void make_anti(int node,int k)
    {
        int rotate = k%4;
        int tN = tree[node].N,tE = tree[node].E,tW = tree[node].W,tS = tree[node].S;
        if(rotate == 1)
        {
            tree[node].E = tS ; tree[node].W = tN;
            tree[node].N = tE ; tree[node].S = tW;
        }
        if(rotate == 2)
        {
            tree[node].E = tW ; tree[node].W = tE;
            tree[node].N = tS ; tree[node].S = tN;
        }
        else if(rotate == 3)
        {
            tree[node].E = tN ; tree[node].W = tS;
            tree[node].N = tW ; tree[node].S = tE;
        }
    }

    void prepare(int node,int b,int e)
    {
        //lazily updating the child for i) sum & ii)add
        //transfering the responsibility of add to child node
        clock[2*node] += clock[node];
        clock[2*node+1] += clock[node];

        anti[2*node] += anti[node];
        anti[2*node+1] += anti[node];
        
        int mid = (b+e)/2;

        make_clock(2*node,clock[node]);  // no of elements in left half(child) of node=(mid-b+1)
        make_clock(2*node+1,clock[node]);  // when subtracting it does not include minuend 

        make_anti(2*node,anti[node]);  // no of elements in left half(child) of node=(mid-b+1)
        make_anti(2*node+1,anti[node]);  // when subtracting it does not include minuend 
        
        clock[node]=0;  // release add of node
        anti[node]=0;
    }
    void update(int node,int b,int e,int i,int j,int  k,int f)
    {
        if(i>e || j<b) // be ij or ij be  //out of range
            return ;
        if(b>=i && e<=j) // i be j    
        {
            //in range update directly (sum and add) matrix 
            //without going to child
            if(f == 0)
            {
                make_clock(node,k);
                clock[node] += (k%4);         // flag for next update  later on
            }
            else 
            {
                make_anti(node,k);
                anti[node] += (k%4);
            }
        }
        else  // not entirely in range
        {
            // then we have to go to child (2*node & 2*node+1)
            // before going to child (prepare the child for update 
            // using add matrix)
            prepare(node,b,e);
            int mid=(b+e)/2;
            update(2*node,b,mid,i,j,k,f);
            update(2*node+1,mid+1,e,i,j,k,f);
            tree[node] = combine_data(tree[2*node],tree[2*node+1]); // updating the node after updating the child
        }

    }
    data query(int node,int b,int e,int i,int j)
    {
        if(i>e || j<b)
            return make_data(0);
        if(b>=i && e<=j)
            return tree[node];
        prepare(node,b,e);//before going to child update add & sum of child
        int mid=(b+e)/2;
        return combine_data(query(2*node,b,mid,i,j) , query(2*node+1,mid+1,e,i,j));

    }
}
using namespace segmentTree;
int main()
{
    ios::sync_with_stdio(false);
    int n,m,l,r,k;
    char ch;
    memset(segmentTree::clock,0,sizeof(segmentTree::clock));
    memset(anti,0,sizeof(anti));
    cin>>n>>m;
    init_tree(1,1,n);
    rep(i,m)
    {
        cin>>ch;
        if(ch == 'C') 
        {
            cin>>l>>r>>k;
            update(1,1,n,l,r,k,0);
        }
        else if(ch == 'A')
        {
            cin>>l>>r>>k;
            update(1,1,n,l,r,k,1);
        }
        else if(ch == 'Q') 
        {
            cin>>l>>r;
            data q = query(1,1,n,l,r);
            cout << q.maxx << endl;
        }
    }
    return 0; 
}
