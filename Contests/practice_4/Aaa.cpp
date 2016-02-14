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
#define MAX 100010
#define MOD 1000000007
int n,arr[1010];
int mem[1010][1010];
int pos[1010][1010];
int solve(int i,int j){
	if(i+1 == j)	return 0;

	int& res = mem[i][j];
	if(res != -1)	return res;

	res = 0;
	for(int k=i+1;k<j;k++)
		if(arr[i]*arr[k]*arr[j] + solve(i,k)+solve(k,j) >= res){
			res = arr[i]*arr[k]*arr[j] + solve(i,k)+solve(k,j);
			pos[i][j] = k;
		}

	return res;
}
void print(int i,int j){
	if(i+1 == j)	return;
	print(i,pos[i][j]);
	print(pos[i][j],j);
	cout<<pos[i][j]<<endl;
}
int main()
{_
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	memset(mem,-1,sizeof mem);

	cout<<solve(0,n-1)<<endl;
	print(0,n-1);
	return 0; 
}
