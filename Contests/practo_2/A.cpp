#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define all(v)                      v.begin(),v.end()	
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007

vector<int> adjList[1010];
int visited[1010];
void dfs(int node){
	visited[node] = 1;
	int size = adjList[node].size();
	for(int i=0;i<size;i++){
		int child = adjList[node][i];
		if(child != node && !visited[child]) dfs(child);
	}
}
int main()
{_
	int n,p;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p;
		adjList[i].push_back(p);
		adjList[p].push_back(i);
	}

	
	int cnt = 0;
	for(int i=2;i<=n;i++)
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	cout<<cnt<<endl;

	return 0; 
}
