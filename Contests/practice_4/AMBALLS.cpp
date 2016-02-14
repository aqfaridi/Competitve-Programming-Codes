#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define all(v)                      v.begin(),v.end()	
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 210
#define MOD 1000000007
LL mem[MAX][MAX][MAX];
int arr[MAX],n,sum,cnt[MAX];
LL solve(int idx,int prev,int minus){
	if(idx == sum)	return (minus == 0);

	LL& res = mem[idx][prev][minus];
	if(res != -1)	return res;

	res = 0;
	for(int i=1;i<=n;i++)
		if(cnt[i] < arr[i]){
			cnt[i]++;
			res = (res + solve(idx+1,i,minus + (prev == i)))%MOD;
			cnt[i]--;
		}
	/*
		if(i != prev && (cnt[i] < arr[i])){
			cnt[i]++;
			res = (res + solve(idx+1,i))%MOD;
			cnt[i]--;
		}
	*/
	return res;
}
int main()
{_
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum = 0;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			sum += arr[i];
		}
		memset(cnt,0,sizeof cnt);
		memset(mem,-1,sizeof mem);
		int ans = solve(0,0,0);
		cout<<ans<<endl;
	}
	return 0; 
}
