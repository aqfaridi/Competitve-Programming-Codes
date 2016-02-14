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
int arr[MAX],mark[MAX];
int main()
{_
	int t,n;
	t = 1;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int prev = arr[0];
		int ans = 0,cnt = 0;
		bool f = false;

		do{
			f = false;
			prev = arr[0];
			for(int i=1;i<n;i++){
				if(!mark[i] && arr[i] > prev){
					mark[i] = 1;
					prev = arr[i];
					f = true;
				}
				else if(!mark[i])
					prev = arr[i];
			}
			if(f) cnt++;
			if(cnt > 100)	break;
		}while(f);

		cout<<cnt<<endl;
		/*
		for(int i=0;i<n;i++)
			cout<<mark[i]<<" \n"[i==n];
		*/
	}
	return 0; 
}
