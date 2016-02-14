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

int cnt;
set<string> sett;
string str;
void solve(string m,stack<char> s,string b){
	
	string m1(m);
	stack<char> s1(s);
	string b1(b);

	string m2(m);
	stack<char> s2(s);
	string b2(b);
	
	if(b1.empty()){
		while(!s1.empty()){
			m1.push_back(s1.top());
			s1.pop();
		}
		if(m1.compare(str) == 0)
			cnt++;
		sett.insert(m1);
		return;
	}
	else{
		if(!s2.empty()){
			m2.push_back(s2.top());
			s2.pop();
			solve(m2,s2,b2);
		}
		
		s1.push(b1[0]);
		b1.erase(0, 1);
		solve(m1,s1,b1);
	}	
}


int main()
{_
	cin>>str;
	string s;
	stack<char> st;
	solve(s,st,str);
	cout<<cnt<<" "<<sett.size()<<endl;
	return 0;
}
