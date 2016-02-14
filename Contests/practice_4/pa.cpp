#include <bits/stdc++.h>
using namespace std;
int input[20];
int store[40000][20],n;
int precompute(int pankaj,int past){
	int total = __builtin_popcount(pankaj);
	if(total == n)
		return 0;

	int& answer = store[pankaj][past];
	if(answer != -1)	return answer;

	answer = 0;
	for(int i=0;i<n;i++){
		if(!(pankaj&(1<<i))){
			if(input[i] - input[past] >= 0)
				answer = max(answer,(total+1)*(input[i]-input[past]) + precompute((pankaj|(1<<i)),i));
			else
				answer = max(answer,(total+1)*(input[past]-input[i]) + precompute((pankaj|(1<<i)),i));
		}
	}
	
	return answer;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>input[i];
		memset(store,-1,sizeof store);
		int ans = 0;
		for(int i=0;i<n;i++)
			ans = max(ans,precompute((1<<i),i));
		cout<<ans<<endl;
	}
	return 0; 
}
