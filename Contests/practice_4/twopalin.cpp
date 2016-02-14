#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define endl '\n'
int n,result;
int marked_this[26];
string s1,s2;
int base(string &s1){
	int a = 0;
	memset(marked_this,0,sizeof marked_this);
	for(int i=0;i<n;i++)
		marked_this[s1[i]-'a']++;
	for(int i=0;i<26;i++)
		if(marked_this[i]) a++;
	return a;
}
void solve(int pos){
	if(pos == n){
		int a = 0 , b = 0;
		a = base(s1);
		b = base(s2);
		result = min(result,max(a,b));
		return;
	}
	swap(s1[pos],s2[pos]);
	solve(pos+1);
	swap(s1[pos],s2[pos]);
	solve(pos+1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s1;
		cin>>s2;
		result = INT_MAX;
		solve(0);
		cout<<result<<endl;
	}
	return 0; 
}
