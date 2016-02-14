#include<bits/stdc++.h>
using namespace std;
int a[2005][2005];
vector<int> v[2005];
vector<int> vv[2005];
int main(){
	int n,cnt=0,ans=0;
	char ch;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>ch;
			a[i][j] = (int)ch-48;
			if(ch == '1')
				v[i].push_back(j);
			if(ch = '0')
				vv[i].push_back(j);
		}
	}
	ans  = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<vv[i].size();j++){
			if(vv[i][j] <= i)continue;
			for(int k=0;k<v[i].size();k++){
				if(a[i][v[i][k]] == 1 and a[vv[i][j]][v[i][k]] == 1)
				{
					cout<<a[i][v[i][k]]<< "  " << a[vv[i][j]][v[i][k]]<<endl;
					ans += 2;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
