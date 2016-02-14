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
LL dp[MAX][MAX];
int arr[MAX],n,spaces[MAX];
LL C[MAX][MAX];
void pre(){
	for(int n=0;n<=200;n++)
		C[n][0] = 1;
	for(int n=1;n<=200;n++)
		for(int r=1;r<=200;r++)
			C[n][r] = (C[n-1][r-1] + C[n-1][r])%MOD;
}
int main()
{_
	pre();
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		spaces[0] = 1;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			spaces[i] = (spaces[i-1] + arr[i]);
		}

		memset(dp,0,sizeof dp);
		dp[0][0] = 1;
		for(int x=1;x<=n;x++) // for all colors
			for(int ij=0;ij<=arr[x];ij++) // fill all possible arr[i]
				for(int b=0;b<=spaces[x-1];b++){// for all bad spaces
					if(dp[x-1][b] > 0){
						for(int k=0;k<=min(b,ij);k++){ // partition good & bad spaces
							int gs = ij-k; // good to select
							int good = spaces[x-1] - b; // total good 
							dp[x][(b-k) + (arr[x]-ij)] += (((dp[x-1][b] * C[b][k])%MOD * C[good][gs])%MOD * C[arr[x]-1][ij-1])%MOD;
							dp[x][(b-k) + (arr[x]-ij)]  %= MOD;
						}
					}
				}

		cout<<dp[n][0]<<endl;
	}
	return 0; 
}
