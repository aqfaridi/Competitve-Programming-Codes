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
int arr[MAX];
int main()
{_
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int f = 1;
		for(int i=n,k=n;i>=n/2;i--){
			if(k < 0)	break;
			arr[k--] = i;
			arr[k--] = f++;
		}
		for(int i=1;i<=n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0; 
}
