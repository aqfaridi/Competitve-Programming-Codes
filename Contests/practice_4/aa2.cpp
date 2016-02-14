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

LL power(LL a,LL b,LL m)
{
	LL d=1;
	while(b)
	{
		if(b&1)
			d=(d*a)%m;
		a=(a*a)%m;
		b=b>>1;
	}
	return d%m;
}
LL nCr(LL n,LL r,LL m)
{
	LL dp[102][102];
memset(dp,0,sizeof dp);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=r && j<=i;j++)
		{
			if(j==0 || j==i)
				dp[i][j]=1;
			else
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%m;
		}
	}
	return dp[n][r]%m;
}
LL lucas(LL n,LL r,LL m)
{
	if(n==0 && r==0)
		return 1;
	LL ni=n%m;
	LL ri=r%m;
	if(ri>ni)
		return 0;
	return lucas((n/m),(r/m),m)*nCr(ni,ri,m);
}
int main()
{
   	/*int ch;
   	int r;
   	char s[12];
   	char *chptr;*/
   	//freopen("samin.txt","r",stdin);
   	//freopen("samout.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	LL primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	int t;
	cin>>t;
	while(t--)
	{
		LL n,r,m,tmp;
		cin>>n>>r>>m;
		n-=1;
		r-=1;
		if(r>n)
		{
			cout<<"0"<<endl;
			continue;
		}
		tmp=m;
		vector<LL>fact,aa;
		// lucas
		for(int i=0;i<25;i++)
		{
			if(tmp%primes[i]==0 && tmp>1)
			{
				fact.pb(primes[i]);	
				tmp/=primes[i];
			}	
		}	
		for(int i=0;i<fact.size();i++)
		{
			aa.pb(lucas(n,r,fact[i]));
		}
		// chinese remainder 
		LL sum=0;
		for(int i=0;i<fact.size();i++)
		{
			LL p=m/fact[i];
			sum=(sum+((((p*aa[i])%m)*power(p,fact[i]-2,fact[i]))%m))%m;
		}
		cout<<sum%m<<endl;
	}
	return 0;
}