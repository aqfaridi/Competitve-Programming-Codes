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
set<string> s;
vector<string> v;
int main()
{_
	int n;
	cin>>n;
	string str;
	for(int i=0;i<n+1;i++){
		char ch = getchar();
		getline(cin,str);
		int l = str.length();
		string ans = "";
		for(int j=0;j<l;j++){
			if(str.substr(j,7) == "http://"){
				ans = "";
				int k = j+7;
				string pref = str.substr(j+7,4);
				if(pref == "www." || pref == "web." || pref == "ww2")
					k = j+11;
				for(;k<l;k++){
					if(!isalpha(str[k]) && !isdigit(str[k]) && str[k]!='.' && str[k]!='-'){
						int len = ans.length();
						if((ans[len-3] == '.' || ans[len-4] == '.') )
						s.insert(ans);
						j = k;
						break;
					}
					ans += str[k];
				}
			}
			if(str.substr(j,8) == "https://"){
				ans = "";
				int k = j+8;
				string pref = str.substr(j+8,4);
				if(pref == "www." || pref == "web." || pref == "ww2")
					k = j+12;
				for(;k<l;k++){
					if(!isalpha(str[k]) && !isdigit(str[k]) && str[k]!='.' && str[k]!='-'){
						int len = ans.length();
						if((ans[len-3] == '.' || ans[len-4] == '.') )
							s.insert(ans);
						j = k;
						break;
					}
					ans += str[k];
				}
			}
			
		}
	}
	set<string>::iterator it = s.begin();
	for(;it != s.end();it++)
		v.push_back((*it));

	int size = v.size();
	for(int i=0;i<size-1;i++)
		cout<<v[i]<<";";
	cout<<v[size-1];

	return 0; 
}
