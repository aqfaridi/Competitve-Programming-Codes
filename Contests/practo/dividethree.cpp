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

#define endl '\n'
#define MAX 100010
#define MOD 1000000007

int arr[13];
int n;
string base3(int N){
	string str="";
	while(N){
		int rem = N%3;
		str += (rem+'0');
		N/=3;
	}
	int l = str.length();
	for(int i=0;i<n-l;i++)
		str.append("0");
	reverse(all(str));
	return str;
}
int main()
{_
	int s1,s2,s3;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>arr[i];
	int pwr = pow(3,n);
	int ans = INT_MAX;
	for(int i=0;i<pwr;i++){
		int N = i;
		string str = base3(N);
		s1 = s2 = s3 = 0;
		for(int j=0;j<n;j++){
			if(str[j] == '0')	s1 += arr[j];
			else if(str[j] == '1')	s2 += arr[j];
			else s3 += arr[j];
		}
		ans = min(ans,max(s1,max(s2,s3)));
	}
	cout<<ans<<endl;
	return 0; 
}
