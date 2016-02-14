#include <bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define endl '\n'
#define MAX 100010
#define MOD 1000000007

int pooja[20];
int dp[40000][20],n;
int recursion(int mask,int pichla){
		int sum = __builtin_popcount(mask);
		if(sum == n)	return 0;

		int& value_result = dp[mask][pichla];
		if(value_result != -1)	return value_result;

		value_result = 0;
		for(int i=0;i<n;i++){
			if(!(mask&(1<<i))){
				if(pooja[i] - pooja[pichla] >= 0)
					value_result = max(value_result,(sum+1)*(pooja[i]-pooja[pichla]) + recursion((mask|(1<<i)),i));
				else
					value_result = max(value_result,(sum+1)*(pooja[pichla]-pooja[i]) + recursion((mask|(1<<i)),i));
			}
		}
	
	return value_result;
}
int main()
{_
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>pooja[i];
		memset(dp,-1,sizeof dp);
		int maxed_value = 0;
		for(int i=0;i<n;i++)
			maxed_value = max(maxed_value,recursion((1<<i),i));

		cout<<maxed_value<<endl;
	}
	return 0; 
}
