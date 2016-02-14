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
#define MAX 1000010
#define MOD 1000000007
int arr[MAX];
int sum(int n){
	if(n < 0)	return 0;

	if((n&1))
		return (n/2 + 1);
	else
		return n/2;
}
int main()
{_
	int n,k;
	cin>>n>>k;
	for(int i=0;i<k;i++)
		cin>>arr[i];
	sort(arr,arr+k);
	int ans = k;
	ans += sum(arr[0]-2);
	for(int i=1;i<k;i++)
		ans += sum(arr[i]-arr[i-1]-3);
	ans += sum(n-arr[k-1]-1);
	cout<<ans<<endl;
	return 0; 
}
