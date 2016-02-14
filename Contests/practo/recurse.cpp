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

#define MAX 100010
#define MOD 1000000007
vector<int> arr;
int dp[1010][1010];
int f(int x,int y){

	int& res = dp[x][y];
	if(res != -1)	return res;
	if(x == 0)	return res = (y+1)%1000;
	if(x > 0 && y == 0) return res = f(x-1,1);
	if(x>0 && y>0) return res = f(x-1,f(x,y-1));
}
int main()
{_
	int x,y;
	cin>>x>>y;
	memset(dp,-1,sizeof dp);
	cout<<setw(3)<<setfill('0')<<f(x,y)<<endl;
	return 0; 
}
