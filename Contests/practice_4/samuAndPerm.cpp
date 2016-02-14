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
int arr[20];
int mem[40000][20],n;
int solve(int mask,int prev){
	int cnt = __builtin_popcount(mask);
	if(cnt == n)
		return 0;

	int& res = mem[mask][prev];
	if(res != -1)	return res;

	res = 0;
	for(int i=0;i<n;i++){
		if(!(mask&(1<<i))){
			if(arr[i] - arr[prev] >= 0)
				res = max(res,(cnt+1)*(arr[i]-arr[prev]) + solve((mask|(1<<i)),i));
			else
				res = max(res,(cnt+1)*(arr[prev]-arr[i]) + solve((mask|(1<<i)),i));
		}
	}
	
	return res;
}
int main()
{_
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		memset(mem,-1,sizeof mem);
		int ans = 0;
		for(int i=0;i<n;i++)
			ans = max(ans,solve((1<<i),i));

		cout<<ans<<endl;
	}
	return 0; 
}
