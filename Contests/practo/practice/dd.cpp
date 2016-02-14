#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 
#include <climits>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()	
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
	
#define debug                       if(1)
#define debugoff                    if(0)	

#define print(x)                 cerr << x << " ";    
#define pn()				     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 1000010
#define MOD 1000000007
#define p 29
LL pre_hash[MAX];
LL mod_expo(LL a,LL n,LL m)
{
	LL result = 1;
	while(n)
	{
		if((n&1))
			result = (result*a)%m;
		a = (a*a)%m;
		n >>= 1;
	}
	return result%m;
}

LL Hash(int i, int j)
{
    LL ret = ((pre_hash[j] - ((i-1>=0)?pre_hash[i-1]:0) + MOD)%MOD * mod_expo(p,MOD-i-1,MOD))%MOD;
    return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	string str;
	int q,l,l1,r1,l2,r2;
	cin>>str;
	l = str.length();
	pre_hash[0] = 0;
	LL P = 1;
	for(int i=0;i<l;i++){
	    pre_hash[i] = (((i-1>=0)?pre_hash[i-1]:0) + ((str[i]-'a'+1)*P)%MOD)%MOD;
	    //cout<<pre_hash[i]<<" ";
	    P = (P*p)%MOD;
	}

	cin>>q;
	while(q--){
		cin>>l1>>r1>>l2>>r2;
		l1 -= 1; r1 -= 1;
		l2 -= 1; r2 -= 1;
		//cout<<Hash(l1,r1)<<endl;
		//cout<<Hash(l2,r2)<<endl;
		if(Hash(l1,r1) == Hash(l2,r2))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	
	return 0; 
}