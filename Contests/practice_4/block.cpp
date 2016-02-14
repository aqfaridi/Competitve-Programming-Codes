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
string str;
int l;
set<string> st;
void solve(int idx,string s){
	if(idx == l){
		st.insert(s);
		cout<<s<<endl;
		return;
	}

	for(int j=idx;j<l;j++){
		string sub = str.substr(idx,j-idx+1);
		for(int i=0;i<(1<<l);i++)
			for(int k=0;k<l;k++)
				if(((1<<k)&i)){
					sub += str[i];
		reverse(sub.begin(),sub.end());	
		solve(j+1,s+sub);
	} 
	
}
int main()
{_
	cin>>str;
	l = str.length();
	solve(0,"");
	/*
	for(auto it=st.begin();it != st.end();it++)
		cout<<(*it)<<endl;

	cout<<st.size()-1<<endl;
	*/
	return 0; 
}
