#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define all(v)                      v.begin(),v.end()	
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
string s[1010];
string text;
int x = 1;
void precompute(string str){
	int l = str.length();
	string sub = "";
	s[0] = str;
	while(1){
		for(int j=0;j<l/2;j++){
			sub += str[j];
			sub += str[l-j-1];
		}
		if((l&1))
			sub += str[l/2];

		if(sub == text)	break;

		s[x++] = sub;
		str = sub;
		sub = "";
	}
}
int main()
{_
	int k;
	cin>>k>>text;
	precompute(text);
	int idx = (x-k)%x;
	cout<<s[idx]<<endl;
	return 0; 
}
