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

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > tri;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector< pii > vpii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define fore(i,a,b)                 for(int i=a;i<=b;i++)
#define rep(i,n)                    forr(i,0,n)
#define all(v)                      v.begin(),v.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)

#define debug                       if(1)
#define debugoff                    if(0)

#define print(x)                 cerr << x << " ";
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
string str[1000010];
int pos[1000010];
int main(){
	int L;
	cin>>L;

	LL nodes = ((1LL<<L) - 1);

	for(int i=1;i<=nodes;i++)
		cin>>str[i];
	
	//setting initial condition for pos
	if(str[nodes] != "#")
	    pos[nodes] = nodes;
	else 
	    pos[nodes] = -1;
	    
	for(int i = nodes-1;i>=1;i--){
	    if(str[i] == "#")
	        pos[i] = pos[i+1];
	    else
	        pos[i] = i;
	}	
	
	//printing level wise leftmost element
	for(int i=0;i<L;i++){
	    if(str[(1LL << i)] == "#")
	        cout<<str[pos[(1LL << i)]]<<" ";
	    else
	        cout<<str[(1LL << i)]<<" ";
	}
	cout<<endl;
	
 	return 0;
}