#include <bits/stdc++.h>
using namespace std;
#define MAX 3005
int a[MAX][MAX];
vector<int> v[3005];
int check[3005][3005];
queue<int> que;
int main()
{
    int n,c;
    int ans = 0;
    char ch;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>ch;
			a[i][j] = (int)ch-48;
			if(ch == '1')
				v[i].push_back(j);
		}
	}
    int sz = 0;
    for(int i=1;i<=n;i++){
	sz = v[i].size();
        for(int j=0;j<sz;j++)
            que.push(v[i][j]);
        while(!que.empty()){
            c = que.front();
            que.pop();
            for(int j=0;j<v[c].size();j++) {
                if(v[c][j] == i)    continue;                      //dobara father
                if(!check[i][v[c][j]] && a[i][v[c][j]] == 0) {
                    ans +=2;
                    check[i][v[c][j]] = check[v[c][j]][i] = 1;
                }
            }       
        }
    }
    cout<<ans<<endl;
    return 0; 
}
