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

int arr[MAX],lt[MAX],rt[MAX];
int main()
{_
	int n,i;
	cin>>n;
	for(int i=0;i<n;i++)	
		cin>>arr[i];
	for(lt[0]=1,i=1;i<n;i++)
		lt[i] = ((arr[i]>arr[i-1])?lt[i-1]+1:1);

	int ans = max(lt[n-1],rt[n-1]);
	for(rt[n-1]=1,i=n-2;i>=0;i--){
		rt[i] = ((arr[i]>arr[i+1])?rt[i+1]+1:1);
		ans += max(lt[i],rt[i]);
	}
	cout<<ans<<endl;

	return 0; 
}
