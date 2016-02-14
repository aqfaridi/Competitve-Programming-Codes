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
#define MAX 5010
#define MOD 1000000007
int fee[MAX],T,M,K;
long double p[MAX],dp[MAX][MAX];

int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>T>>M>>K;
		for(int i=1;i<=M;i++)	cin>>fee[i]>>p[i];

		//base case
		for(int s=0;s<=T;s++){
			for(int g=0;g<=M-K;g++)	dp[s][g] = 1;
			for(int g=M-K+1;g<=M;g++)	dp[s][g] = 0;
		}


		for(int idx=1;idx<=M;idx++)
			for(int s=T;s>=fee[idx];s--)
				for(int g=1;g<=M;g++)		
					dp[s][g] = max(dp[s][g],p[idx]*dp[s-fee[idx]][g-1] + (1-p[idx])*dp[s-fee[idx]][g]);
				
		long double ans = dp[T][M];
		cout<<fixed<<setprecision(6)<<ans<<endl;
	}
	return 0; 
}
