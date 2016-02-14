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

#define MAX 100010
#define MOD 1000000007
#define endl '\n'
unsigned long long pwr[25];
LL expo(LL a,LL n)
{
	LL result = 1;
	while(n)
	{
		if((n&1))
			result *= a;
		a *= a;
		n >>= 1;
	}
	return result;
}
set<unsigned long long> s;
void pre(){
    for(int i=1;i<23;i++){
        pwr[i] = expo(7,i);
        s.insert(pwr[i]);
    }
    
    unsigned long long sum = 0;
    int n = 22;
    cout<<n*(1<<n)<<endl;
    for(int i=0;i<(1<<n);i++){
        sum = 0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))
                sum += pwr[j];
        } 
        s.insert(sum);
    }
    cout<<s.size()<<endl;
 
}
int main()
{
    pre();
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
	}
	return 0; 
}