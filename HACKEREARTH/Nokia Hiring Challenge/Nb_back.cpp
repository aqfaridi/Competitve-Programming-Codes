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
int arr[210],barr[210],q,n;
LL dp[10][8000010];
int main()
{_
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) cin>>barr[i];
	cin>>q;

	memset(dp,0,sizeof dp);

	for(int val = 1000010-q;val <= q+1000010;val++)
		dp[n][val] = 1;

	for(int i=n-1;i>=0;i--)
		for(int j=q+2000010;j>=0;j--){
			LL a = (j + arr[i] - barr[i] >= 0)?dp[i+1][j + arr[i] - barr[i]]:0;
			LL b = (j + arr[i] >= 0)?dp[i+1][j + arr[i]]:0;
			LL c = (j - barr[i] >= 0)?dp[i+1][j - barr[i]]:0;
			LL d = (j >= 0)?dp[i+1][j]:0;
			dp[i][j] = (a + b + c + d)%MOD;
			//if(dp[i][j] > 0) cout<<dp[i][j]<<endl;
		}

	cout<<dp[0][1000010]<<endl;
	return 0; 
}
