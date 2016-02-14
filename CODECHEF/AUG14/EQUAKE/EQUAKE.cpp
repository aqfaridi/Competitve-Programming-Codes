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

#define MAX 8000010
#define MOD 1000000007
int input[MAX];
int pwr[] = {1,10,100,1000,10000};
vector<int> dg;
namespace segmentTree
{
    struct data{
        int mx[12];
    };
    data tree[3*MAX];
    int flag[3*MAX],d,num;
    data combine_data(data left,data right)
    {
        data res;
        rep(i,12)
            res.mx[i] = max(left.mx[i],right.mx[i]);
        return res;
    }
    data make_data(int val)
    {
        data res;
        if(val == 0){
            rep(i,12)
                res.mx[i] = 0;
            return res;
        }
        d = log10(val)+1;
        rep(j,d)
           dg.pb((val/pwr[j])%10);
        reverse(dg.begin(),dg.end());
        res.mx[0] = val;

        for(int j=1;j<d;j++){
           num = 0;
           rotate(dg.begin(),dg.begin()+1,dg.end());
           rep(k,d)
               num = num*10 + dg[k];
           res.mx[j] = num;
        }
        for(int j=d;j<=11;j++)
            res.mx[j] = res.mx[j%d];
        dg.clear();
        return res;
    }
    void init_tree(int node,int b,int e)
    {
        if(b==e)
        {
            tree[node] = make_data(input[b]);
            return ;
        }
        int mid = (b+e)/2;
        init_tree(2*node,b,mid);
        init_tree(2*node+1,mid+1,e);
        tree[node] = combine_data(tree[2*node],tree[2*node+1]);
    }
    void make_flag(int node,int f)
    {
        f = f%12;
        rotate(tree[node].mx,tree[node].mx+f,tree[node].mx+12);
    }

    void prepare(int node,int b,int e)
    {
        flag[2*node] += flag[node];
        flag[2*node+1] += flag[node];

        int mid = (b+e)/2;

        make_flag(2*node,flag[node]);  
        make_flag(2*node+1,flag[node]);  
        
        flag[node]=0; 
    }
    void update(int node,int b,int e,int i,int j,int f)
    {
        if(i>e || j<b) 
            return ;
        if(b>=i && e<=j)     
        {
            make_flag(node,f);
            flag[node] += (f%12);   
        }
        else  
        {
            prepare(node,b,e);
            int mid=(b+e)/2;
            update(2*node,b,mid,i,j,f);
            update(2*node+1,mid+1,e,i,j,f);
            tree[node] = combine_data(tree[2*node],tree[2*node+1]); 
        }

    }
    data query(int node,int b,int e,int i,int j)
    {
        if(i>e || j<b)
            return make_data(0);
        if(b>=i && e<=j)
            return tree[node];
        prepare(node,b,e);
        int mid=(b+e)/2;
        return combine_data(query(2*node,b,mid,i,j) , query(2*node+1,mid+1,e,i,j));

    }
}
using namespace segmentTree;
int main()
{
    ios::sync_with_stdio(false);
    memset(flag,0,sizeof(flag));
    int t,n,q,type,l,r,f;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>input[i];

    init_tree(1,1,n);

    cin>>q;
    while(q--)
    {
        cin>>type;
        if(!type){
            cin>>l>>r>>f;
            l+=1; r+=1;
            update(1,1,n,l,r,f);
        }
        else{
            cin>>l>>r;
            l+=1; r+=1;
            data node = query(1,1,n,l,r);
            cout<<node.mx[0]<<endl;
        }
    }
    return 0; 
}
