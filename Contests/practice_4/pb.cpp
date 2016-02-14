#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,d,q,resultvalue;
int inputarray[110][110],markedarray[110][110];
int xcordirection[] = {1,-1,0,0};
int ycordirection[] = {0,0,1,-1};
void depthfirstsearch(int x,int y){
	if(x < 0 || x >= n || y < 0 || y >= m)	return;

	resultvalue++;
	markedarray[x][y] = 1;
	for(int i=0;i<4;i++)
		if(!markedarray[x + xcordirection[i]][y + ycordirection[i]] && abs(inputarray[x + xcordirection[i]][y + ycordirection[i]] - inputarray[x][y]) <= d )
			depthfirstsearch(x + xcordirection[i] , y + ycordirection[i]);
}
int main()
{
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>inputarray[i][j];
	while(q--){
		cin>>x>>y>>d;
		x -= 1; y -= 1;
		resultvalue = 0;
		memset(markedarray,0,sizeof markedarray);
		depthfirstsearch(x,y);
		cout<<resultvalue<<endl;
	}

	return 0; 
}
