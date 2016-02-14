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
int main()
{_
	LL a,b,c;
	cin>>a>>b>>c;
	LL cnt = 0;
	for(int i=0;i<=a;i++){
		cout<<c-i<<" "<<b<<endl;
		cnt += min(c-i,b);
	}

	LL g = __gcd(cnt,a*b);
	cout<<cnt/g<<"/"<<(a*b)/g<<endl;

	return 0; 
}
