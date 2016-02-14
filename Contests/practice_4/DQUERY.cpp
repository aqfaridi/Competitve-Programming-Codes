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
#define MAX 1000010
#define MOD 1000000007
namespace MO_algorithm{
	int cnt[MAX],arr[MAX],ret[MAX],ans = 0;
	void add(int idx){
		cnt[arr[idx]]++;
		if(cnt[arr[idx]] == 1)
			ans++;
	}
	void remove(int idx){
		cnt[arr[idx]]--;
		if(cnt[arr[idx]] == 0)
			ans--;
	}
	vector< tuple<int,int,int> > q;
	#define BLOCK 555
	bool cmp(tuple<int,int,int> a,tuple<int,int,int> b){
		if(get<0>(a)/BLOCK != get<0>(b)/BLOCK) //diff blocks
			return get<0>(a)/BLOCK < get<0>(b)/BLOCK;
		else
			return get<1>(a) < get<1>(b);
	}
	void query(){
		int n,Q,x,y;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];

		int L = 0 , R = 0;
		cin>>Q;	
		for(int i=0;i<Q;i++){
			cin>>x>>y;
			x-=1; y-=1;
			q.eb(mt(x,y,i));
		}
		sort(q.begin(),q.end(),cmp);

		for(int i=0;i<Q;i++){
			x = get<0>(q[i]);
			y = get<1>(q[i]);
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
	}
}
using namespace MO_algorithm;
int main()
{_
	query();
	return 0; 
}
