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
vector<int> arr;
int main()
{_
	fstream f1,f2;
	string s2,s1;
	f1.open("out1.txt",fstream::in);
	f2.open("out2.txt",fstream::in);
	while(!f1.eof()){
		//cout<<"he"<<endl;
		getline(f1,s1);
		getline(f2,s2);
		if(s1 != s2)
			cout<<s1<<" "<<s2<<endl;
	}
	return 0; 
}
