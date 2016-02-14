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
stack<char> st;
set<string> stt;
int l,cnt;
void solve(int idx,deque<char> dd){
	deque<char> d;
	cout<<idx<<endl;
	for(int i=0;i<dd.size();i++)
		d.push_back(dd[i]);

	for(int i=0;i<d.size();i++)
		cout<<d[i];
	cout<<endl;

	if(idx == l){
		/*
		string sub = "";
		for(int i=0;i<l;i++)
			cout<<d[i];
		cout<<endl;
		//cout<<sub<<endl;
		if(sub == str)
			cnt++;
		stt.insert(sub);
		*/
		return;
	}

	st.push(str[idx]);
	char c = d[0];
	d.pop_front();
	solve(idx+1,d);


	while(!st.empty()){
		char ch = st.top();
		st.pop();
		d.push_back(ch);
		solve(idx+1,d);
	}
	

}
int main()
{_
	cin>>str;
	deque<char> d;
	l = str.length();
	for(int i=0;i<l;i++)
		d.push_back(str[i]);
	
	solve(0,d);
	cout<<cnt<<" "<<stt.size()<<endl;
	return 0; 
}
