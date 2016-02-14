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
int cnt[MAX],arr[MAX],ret[MAX],ans = 0,maxx;
void add(int idx){
	cnt[arr[idx]]++;
	if(arr[idx] == maxx)
		ans++;
}
void remove(int idx){
	cnt[arr[idx]]--;
	if(arr[idx] == maxx)
		ans--;
}
vector< tuple<int,int,int> > q;
#define BLOCK 400 
bool cmp(tuple<int,int,int> a,tuple<int,int,int> b){
	if(get<0>(a)/BLOCK != get<0>(b)/BLOCK) //diff blocks
		return get<0>(a)/BLOCK < get<0>(b)/BLOCK;
	else
		return get<1>(a) < get<1>(b);
}

namespace segmentTree
{
	int maxv[MAX];
	int tree[3*MAX];
	int combine_int(int left,int right)
	{
		return max(left,right);
	}
	void init_tree(int node,int b,int e)
	{
		if(b==e) // leaf node
		{
			tree[node] = arr[b];
			return ;
		}
		int mid = (b+e)/2;
		init_tree(2*node+1,b,mid);
		init_tree(2*node+2,mid+1,e);
		tree[node] = combine_int(tree[2*node+1],tree[2*node+2]);
	}

	int query(int node,int b,int e,int i,int j)    
	{
		if(b>=i &&  e<=j)//in range   
			return tree[node];
		
		int mid = (b+e)/2;
		if(j<=mid)
			return query(2*node+1,b,mid,i,j);
		else if(i>mid)//not else if ?? can go to both sides
			return query(2*node+2,mid+1,e,i,j);
		int p1 = query(2*node+1,b,mid,i,j);
		int p2 = query(2*node+2,mid+1,e,i,j);
		return combine_int(p1,p2);
	}


}
using namespace segmentTree;

int main()
{_
	int n,Q,x,y;
	cin>>n>>Q;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	init_tree(0,0,n-1);

	int L = 0 , R = 0;
	for(int i=0;i<Q;i++){
		cin>>x>>y;
		x-=1; y-=1;
		q.eb(mt(x,y,i));
	}
	sort(q.begin(),q.end(),cmp);

	for(int i=0;i<Q;i++){
		x = get<0>(q[i]);
		y = get<1>(q[i]);
		maxx = query(0,0,n-1,x,y);
		ans = cnt[maxx];
		//trace3(x,y,maxx);
		while(L < x)
			remove(L++);
		while(L > x)
			add(--L);
		while(R <= y)
			add(R++);
		while(R > y+1)
			remove(--R);
		ret[get<2>(q[i])] = ans; 
	}
	for(int i=0;i<Q;i++)
		cout<<ret[i]<<endl;
	return 0; 
}
