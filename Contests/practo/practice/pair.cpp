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
LL arr[MAX];
int main()
{
	ios::sync_with_stdio(false);
	LL t,n,d;
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		reverse(arr,arr+n);

		LL sum = 0;
		for(int i=0;i<=n-2;){
			//cout<<arr[i]<<" "<<arr[i+1]<<endl;
			if(abs(arr[i]-arr[i+1] < d) && arr[i]+arr[i+1]>0){
				sum += arr[i] + arr[i+1];
				trace1(sum);
				i += 2;
			}
			else
				i++;
		}
		cout<<sum<<endl;
	}
	return 0; 
}