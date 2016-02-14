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
#define MAX 1000010
#define MOD 1000000007
int arr[MAX];
int main()
{_
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if(n == 1){
			cout<<1<<" "<<m-1<<endl;
			continue;
		}
		memset(arr,0,sizeof arr);
		int x = 1 , y = n , f = 1,pos = 1,ans = 1;
		for(int i=1;i<=(m+1)/2;i++){
			if(x == 1 || arr[x] < arr[x-1])
				arr[x++] = f;
			else{
				x = 1;
				if(f <= arr[x])
					f++;
				arr[x++] = f;
			}

			if((m&1)){
				pos = x-1;
				ans = arr[pos]-1;
			}



			if(y == n || arr[y] < arr[y+1])
				arr[y--] = f;
			else{
				y = n;
				if(f <= arr[y])
					f++;
				arr[y--] = f;
			}

			if(!(m&1)){
				pos = y+1;
				ans = arr[pos]-1;
			}

		
		}

		cout<<pos<<" "<<ans<<endl;
		/*
		for(int i=1;i<=n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		*/

	}
	return 0; 
}
