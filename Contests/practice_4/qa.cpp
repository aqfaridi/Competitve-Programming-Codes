#include <bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define endl '\n'
#define MAX 100010
#define MOD 1000000007
int xaxis[] = {1,-1,0,0};
int yaxis[] = {0,0,1,-1};
int n,m,x,y,d,q,result;
int take[110][110],mark[110][110];
void  depth(int x,int y){
		if(x < 0 || x >= n || y < 0 || y >= m)	return;

		result++;
		mark[x][y] = 1;
		for(int i=0;i<4;i++)
			if(!mark[x + xaxis[i]][y + yaxis[i]] && abs(take[x + xaxis[i]][y + yaxis[i]] - take[x][y]) <= d )
				depth(x + xaxis[i] , y + yaxis[i]);
	}
int main()
{_
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>take[i][j];
	while(q--){
		cin>>x>>y>>d;
		x -= 1; y -= 1;
		result = 0;
		memset(mark,0,sizeof mark);
		depth(x,y);
		cout<<result<<endl;
	}

	return 0; 
}
