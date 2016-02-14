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
#define MAX 225
#define MOD 1000000007
#define SZ 101
int arr[MAX][MAX][MAX];
int dp[MAX][MAX][MAX];
void pre(int n){
	int c=1;
	for(int i=c;i<=n;i++)
		for(int j=c;j<=n;j++)
			for(int k=c;k<=n;k++){
				dp[i][j][k] = arr[i][j][k] + dp[i-c][j][k] + dp[i][j-c][k] + dp[i][j][k-c] - dp[i-c][j-c][k] - dp[i][j-c][k-c] - dp[i-c][j][k-c] + dp[i-c][j-c][k-c];
			}
}
int main()
{_
	int n,x,y,z,q;
	int x1,y1,z1,x2,y2,z2;
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>x>>y>>z;
		x += SZ;y += SZ;z += SZ;
		arr[x][y][z] += 1;
	}
	pre(215);
	cin>>q;
	while(q--){
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		x1 += SZ+2; y1 += SZ+2; z1 += SZ+2;
		x2 += SZ; y2 += SZ; z2 += SZ;
		int ans = dp[x2][y2][z2] - dp[x1][y2][z2] - dp[x2][y2][z1] - dp[x2][y1][z2] + dp[x2][y1][z1] + dp[x1][y1][z2] + dp[x1][y2][z1] - dp[x1][y1][z1];
		if(x1 < x2 && y1 < y2 && z1 < z2)
			cout<<ans<<endl;
		else
			cout<<0<<endl;
	}
	return 0; 
}
