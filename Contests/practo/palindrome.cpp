#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define all(v)                      v.begin(),v.end()	
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
bool ispalin(int n){
	string str = to_string(n);
	string rev(str.rbegin(),str.rend());
	return str == rev;
}
int main()
{_
	int t,n,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int ans = 0;
		for(int i=a;i<=b;i++)
			ans += ispalin(i);
		cout<<ans<<endl;
	}
	return 0; 
}
