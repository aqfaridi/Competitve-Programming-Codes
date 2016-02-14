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

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
int b[MAX];
void preprocess(string pat){
	int m = pat.length(),i=0,j=-1;
	b[i] = j;
	while(i<m){
		while(j>=0 && pat[i] != pat[j]) j = b[j];
		i++;j++;
		b[i] = j;
	}
}
void search(string str,string pat){
	int n = str.length(),m = pat.length();
	int i = 0, j = 0;
	while(i<n){
		while(j>=0 && str[i] != pat[j]) j = b[j];
		i++;j++;
		if(j == m){
			cout<<(i-j)<<endl;
			j = b[j];
		}
	}
}
int main()
{_
	string str,sub;
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>str;
		cin>>sub;
		preprocess(sub);
		search(str,sub);
	}
	return 0; 
}
