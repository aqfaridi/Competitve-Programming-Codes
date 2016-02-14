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
#define MAX 37
#define MOD 1000000007
long double dp[MAX][MAX];
int arr[MAX],n,spaces[MAX];
LL C[MAX][MAX];
void pre(){
	for(int n=0;n<=36;n++)
		C[n][0] = 1;
	for(int n=1;n<=36;n++)
		for(int r=1;r<=36;r++)
			C[n][r] = C[n-1][r-1] + C[n-1][r];
}

long double find_ways(int n){
	spaces[0] = 1;
	for(int i=1;i<=n;i++)
		spaces[i] = (spaces[i-1] + arr[i]);

	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	for(int x=1;x<=n;x++) // for all colors
		for(int ij=0;ij<=arr[x];ij++) // fill all possible arr[i]
			for(int b=0;b<=spaces[x-1];b++){// for all bad spaces
				if(dp[x-1][b] > 0){
					for(int k=0;k<=min(b,ij);k++){ // partition good & bad spaces
						int gs = ij-k; // good to select
						int good = spaces[x-1] - b; // total good 
						dp[x][(b-k) + (arr[x]-ij)] += dp[x-1][b] * C[b][k] * C[good][gs] * C[arr[x]-1][ij-1];
					}
				}
			}
	return dp[n][0];
}
long double fact[50];
void make_fact(){
	fact[0] = 1;
	for(int i=1;i<=36;i++)
		fact[i] = fact[i-1]*i;
}
long double perm(int n){
	long double res = fact[n];
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(arr[i] == arr[i - 1]){
			cnt++;
			res /= cnt;
		}
		else {
			cnt = 1;
		}
	}
	return res;
}

long double SUM,CNT;
void solve(int idx,int prev,int sum){
	if(sum == n){
		int cnt = 1;
		for(int i=idx-1;i>1;i--){
			if(arr[i] == arr[i-1])
				cnt++;
			else
				break;
		}

		long double result = perm(idx-1);
		result *= find_ways(idx-1)*C[n][idx-1];
		SUM += cnt*result;
		CNT += result;
		return;
	}

	for(int i=prev;i <= n/2 +1 && sum+i <= n;i++){
		arr[idx] = i;
		solve(idx+1,i,sum+i);
	}
}
double ans[] = {0,1.000000,
2.000000,
2.000000,
1.777778,
1.656250,
1.660800,
1.733668,
1.828592,
1.920742,
1.999589,
2.062219,
2.109256,
2.142717,
2.164972,
2.178301,
2.184725,
2.185964,
2.183446,
2.178343,
2.171597,
2.163963,
2.156033,
2.148263,
2.141000,
2.134497,
2.128932,
2.124422,
2.121035,
2.118798,
2.117709,
2.117741,
2.118848,
2.120971,
2.124043,
2.127988,
2.132728};
int main()
{_
	pre();
	make_fact();
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		SUM = CNT = 0;
		//solve(1,1,0);
		//cout<<fixed<<setprecision(6)<<1.0*SUM/CNT<<","<<endl;
		cout<<fixed<<setprecision(6)<<ans[n]<<endl;
	}
	return 0; 
}

