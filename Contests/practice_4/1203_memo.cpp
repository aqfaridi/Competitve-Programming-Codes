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
double p[MAX],mem[MAX][MAX][MAX];
double solve(int idx,int sum,int g){
	if(sum < 0)	return 0;
	if(idx == 0)	return g < K;

	double& res = mem[idx][sum][g];
	if(res != -1.0)	return res;
	
	res = p[idx]*solve(idx-1,sum-fee[idx],g-1) + (1-p[idx])*solve(idx-1,sum-fee[idx],g); 
	res = max(res,solve(idx-1,sum,g));

	return res;
}
int main()
{_
	
	while(cin>>T>>K){

		if(T == 0 && K == 0)	break;
		for(int i=1;i<=K;i++)
			cin>>fee[i]>>p[i];

		for(int i=0;i<=K;i++)
			for(int j=0;j<=T;j++)	
				for(int g=0;g<=K;g++)
					mem[i][j][g] = -1.0;

		double ans = solve(K,T,K);
		cout<<ans<<endl;
	}
	return 0; 
}
