#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
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

LL mem[22][(1<<11)][11],k;
int num[22];
int transition(int i,int mask){

	for(int x=i;x<=9;x++)
		if(mask&(1<<x))	return (mask^(1<<x))|(1<<i);

	return mask|(1<<i);
}
LL solve(int idx,int mask,int end){
	if(idx == 0)	return (__builtin_popcount(mask) == k);

	LL res = mem[idx][mask][k];
	if(!end && res != -1)	return res;

	res = 0;
	int range = (end)?num[idx]:9;

	for(int i=0;i<=range;i++){
		if(!i && !mask)
			res += solve(idx-1,mask,end && (i==range));
		else
			res += solve(idx-1,transition(i,mask),end && (i==range));
	}

	if(!end) mem[idx][mask][k] = res;
	return res; 
}

LL calc(LL n){
	int idx=0;
	while(n){
		num[++idx] = n%10;
		n/=10;
	}
	return solve(idx,0,1);
}
int main()
{_
	LL t,l,r;
	memset(mem,-1,sizeof mem);
	cin>>t;
	while(t--)
	{
		cin>>l>>r>>k;
		cout<<calc(r)-calc(l-1)<<endl;
	}
	return 0; 
}
