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
int arr[MAX];
int main()
{_
	int n,M;
	cin>>n>>M;
	int cnt = 0,f = 0,idx = n+1;
	for(int i=0;i<n;i++)
		cin>>arr[i];

    int c = 0;
	for(int i=0;i<n;i++){
		if(arr[i] <= M)
			c++;
		else{
			if(f)break;
			else
				f = 1;
		}
	}
	cout<<c<<endl;
	
	return 0; 
}
