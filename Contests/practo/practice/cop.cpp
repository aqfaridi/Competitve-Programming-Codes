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
int arr[500],cop[20];
int main()
{
	ios::sync_with_stdio(false);
	int t,M,x,y;
	cin>>t;
	while(t--)
	{
		memset(arr,0,sizeof arr);
		cin>>M>>x>>y;
		for(int i=0;i<M;i++){
			cin>>cop[i];
			for(int j=cop[i];j<=cop[i] + x*y;j++)
				arr[j] = 1;
			for(int j=cop[i];j >= cop[i]-x*y  && j >= 0;j--)
				arr[j] = 1;
		}
		int cnt = 0;
		for(int i=1;i<=100;i++)
			if(!arr[i])	cnt++;
		cout<<cnt<<endl;
	}
	return 0; 
}