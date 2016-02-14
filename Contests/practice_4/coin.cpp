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
int mem[10010][10010],arr[10010],n,m;
int solve(int idx,int sum){
	if(sum == m)	return 0;
	if(idx == n)	return (1<<20);

	int& res = mem[idx][sum];
	if(res != -1)	return res;

	res = min(solve(idx+1,sum),1 + solve(idx+1,sum + arr[idx]));
	return res;
}
int main()
{_
	cin>>n>>m;
	for(int i=0;i<n;i++)
		arr[i] = i+1;
	int cnt = 0;
	for(int i=n;i>=1;i--){
		if(m >= i){
			m -= i;
			cnt++;
		}
	}

	if(m == 0)
		cout<<cnt<<endl;
	else
		cout<<-1<<endl;
	/*
	memset(mem,-1,sizeof mem);
	int ans = solve(0,0);
	if(ans == (1<<20))
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	*/
	return 0; 
}
