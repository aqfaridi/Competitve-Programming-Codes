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
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
int main(){
	int n , m ;
	cin>>n>>m;
	if(n>0 and m>0){
		cout<<0<<" "<<0<<endl;
		cout<<n<<" "<<m<<endl;
		if(n>=m){
			cout<<0<<" "<<m<<endl;
			cout<<n<<" "<<0<<endl;
		}
		else{
			cout<<n<<" "<<0<<endl;
			cout<<0<<" "<<m<<endl;
		}
	}
	if(n == 0 ){
		cout<<0<<" "<<1<<endl;
		cout<<0<<" "<<m<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<0<<" "<< m-1<<endl;
	}
	if(m == 0){
		cout<<1<<" "<<0<<endl;
		cout<<n<<" "<<0<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<n-1<<" "<<0<<endl;
	}
	return 0;
}

