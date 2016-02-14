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
stack<char> s;
set<string> st;
deque<char> ans;
string str;
int l;

void solve(int idx){
	if(idx == l){
		string sub = "";
		for(int j=0;j<l;j++)
			sub += ans[j];
		st.insert(sub);
		return;
	}

	/*ans.pop_front(); s.push(str[idx]); 
	char ch = s.top();
	s.pop(); ans.push_back(ch);
	*/
	ans.pop_front();
	ans.push_back(str[idx]);
	solve(idx+1);
	//revert
	ans.pop_back();
	ans.push_front(str[idx]);
	solve(idx+1);
}
int main()
{_
	cin>>str;
	l = str.length();
	for(int i=0;i<l;i++)
		ans.push_back(str[i]);
	solve(0);
	for(auto it=st.begin();it != st.end();it++)
		cout<<(*it)<<endl;


	
	cout<<st.size()-1<<endl;
	return 0; 
}
