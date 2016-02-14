#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define mp make_pair
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define endl '\n'
#define MAX 100010
#define MOD 1000000007

int n,q,line;
map<pii,int> cnt;
int a[MAX],b[MAX],c[MAX];
int main()
{_
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		int g = __gcd(a[i],b[i]);
		a[i] /= g;
		b[i] /= g;
		cnt[mp(a[i],b[i])]++;
	}
	cin>>q;
	while(q--){
		cin>>line;
		int ans = cnt[mp(-b[line],a[line])] + cnt[mp(b[line],-a[line])];
		cout<<ans<<endl;
	}
	return 0; 
}
