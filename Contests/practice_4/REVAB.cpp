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

int main()
{_
	int t,n;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>str;
		int l = str.length();
		int maxx = 0,last = 0,pos = 0, c = 0;
		for(int i=0;i<l;i++)
			if(str[i] == 'a')
				c++;

		if(c == l){
			cout<<"0,0"<<endl;
			continue;
		}


		for(int i=0;i<l;i++){
			if(str[i] == 'b'){
				pos = i;
				break;
			}
		}


		string s = str;
		string sub,pat = str.substr(0,pos);
		for(int i=2;i<=l-pos;i++){
			sub = str.substr(pos,i);
			reverse(sub.begin(),sub.end());
			sub = pat + sub + str.substr(pos+i);
			if(s.compare(sub) > 0){
				last = pos + i - 1;
				s = sub;
			}
		}
		cout<<pos<<","<<last<<endl;
	}
	return 0; 
}
