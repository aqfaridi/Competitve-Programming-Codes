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
#define MAX 2010
#define MOD 1000000007
int n;
LL mem[5][MAX][MAX];
LL solve(int idx,int nxt,int sum){
	//trace3(idx,nxt,sum);
	if(idx == 0)	return sum == 0;

	LL& res = mem[idx][nxt][sum];
	if(res != -1)	return res;

	res = 0;
	for(int i=1;i <= nxt && sum-i >= 0;i++)
		res += solve(idx-1,i,sum-i);

	return res;
}
int main()
{_
	int t;
	memset(mem,-1,sizeof mem);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			mem[0][i][0] = 1;
		for(int idx=1;idx<=4;idx++)
			for(int nxt=1;nxt<=n;nxt++)
				for(int sum=1;sum<=n;sum++)
					
		cout<<solve(4,n,n)<<endl;
	}
	return 0; 
}
