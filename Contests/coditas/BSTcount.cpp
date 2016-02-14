#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define endl '\n'
#define MAX 100010
#define MOD 1000000007
LL mem[510][510];
int N,H;
LL solve(int n,int h){
	if(n == 0)	return (h <= H);
	if(n < 0)	return 0;

	LL& res = mem[n][h];
	if(res != -1)	return res;

	res = 0;
	for(int k=1;k<=n;k++)
		res = (res + (solve(k-1,h+1)*solve(n-k,h+1))%MOD)%MOD;
	return res;
}
int main()
{_
	cin>>N>>H;
	memset(mem,-1,sizeof mem);
	LL ans = 0;
	for(LL k=1;k<=N;k++)
		ans = (ans + (k*(solve(k-1,1))%MOD*solve(N-k,1))%MOD)%MOD;
	cout<<ans<<endl;
	return 0; 
}
