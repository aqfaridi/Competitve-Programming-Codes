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
int arr[MAX];
namespace sparseTable{
	int lg2[MAX],ST[MAX][20];
	void make_lg(int n){
		lg2[0] = lg2[1] = 0;
		for(int i=2;i<=n;i++)
			lg2[i] = lg2[i/2] + 1;	
	}
	void build(int n){
		make_lg(n);
		for(int i=0;i<n;i++)
			ST[i][0] = i; // pos of max
		for(int j=1;j<=lg2[n];j++)
			for(int i=0;i+(1<<j)<=n;i++)
				if(arr[ ST[i][j-1] ] > arr[ ST[i+(1<<(j-1))][j-1] ])
					ST[i][j] =  ST[i][j-1]; // maxx pos
				else
					ST[i][j] = ST[i+(1<<(j-1))][j-1];
	}
	int query(int l,int r){
		int k = lg2[r-l+1];
		if(arr[ ST[l][k] ] > arr[ ST[r-(1<<k)+1][k] ])
			return ST[l][k];
		else
			return ST[r-(1<<k)+1][k];
	}
}
using namespace sparseTable;
vector<int> v[MAX];
int main()
{_
	int n,m,l,r;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		v[arr[i]].pb(i);
	}
	build(n);
	while(m--){
		cin>>l>>r;
		l -= 1 ; r -= 1;
		int pos = query(l,r);
		int y = upper_bound(v[arr[pos]].begin(),v[arr[pos]].end(),r) - v[arr[pos]].begin();
		int x = lower_bound(v[arr[pos]].begin(),v[arr[pos]].end(),l) - v[arr[pos]].begin();
		cout<<y-x<<endl;
	}
	return 0; 
}
