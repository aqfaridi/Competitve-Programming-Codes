#include<bits/stdc++.h>
#include<iostream>

using namespace std;

#define mod 1000000007
int a[1005][1005],dp[1005][1005];


int numberOfPaths(int M,int N)
{

	for(int i=0;i<M;i++) {
		if(a[i][0])  dp[i][0]=1;
		else break;
	}
	for(int i=0;i<N;i++) {
		if(a[0][i])  dp[0][i]=1;
		else break;
	}

	for(int i=1;i<M;i++){
		for(int j=1;j<N;j++){
			if(a[i][j]==1){
				dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%mod;
			}
			else dp[i][j]=0;
		}
	}
	return (dp[M-1][N-1]%mod);
}



int main(){
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) {
				cin>>a[i][j];
		}
	}
	cout<<numberOfPaths(m,n)%mod;
	return 0;	
}