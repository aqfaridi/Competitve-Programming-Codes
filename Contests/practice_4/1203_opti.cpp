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
#define MAX 110
#define MOD 1000000007
int fee[MAX],T,K;
double p[MAX],dp[MAX][MAX][MAX];

int main()
{
	while(scanf("%d%d",&T,&K) != EOF){

		if(T == 0 && K == 0)	break;
		int sum = 0;
		for(int i=0;i<K;i++){
			scanf("%d%lf",&fee[i],&p[i]);
			sum += fee[i];
		}
		//	cin>>fee[i]>>p[i];
		for(int i=0;i<=T;i++){
			for(int g=1;g<=K;g++)
				dp[K][i][g] = 1;
			dp[K][i][0] = 0;
		}


		for(int idx=K-1;idx>=0;idx--)
			for(int s=sum-fee[idx];s>=0;s--)
				for(int g=K-1;g>=0;g--)		
					dp[idx][s][g] = max(dp[idx+1][s][g],p[idx]*dp[idx+1][s+fee[idx]][g+1] + (1-p[idx])*dp[idx+1][s+fee[idx]][g]);
				
			/*
		for(int i=0;i<=T;i++)
			cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
			*/	
		double ans = dp[0][0][0];
		printf("%.1f%%\n",ans*100);
		//cout<<ans<<endl;
	}
	return 0; 
}
