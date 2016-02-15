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
int a[210],b[210],Q,n;
LL mem[110][200010];
LL solve(int idx,int val){
	if(idx == n)
		return (val <= Q+200010 && val >= 200010-Q);

	LL& res = mem[idx][val];
	if(res != -1)	return res;

	LL x = solve(idx+1,val + a[idx] - b[idx]);
	LL y = solve(idx+1,val + a[idx]);
	LL z = solve(idx+1,val - b[idx]);
	LL w = solve(idx+1,val);

	res = (x + y + z + w)%MOD;

	return res;
}
int main()
{_
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	cin>>Q;

	memset(mem,-1,sizeof mem);
	cout<<solve(0,200010)<<endl;

	return 0; 
}
