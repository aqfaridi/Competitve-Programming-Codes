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
int arr[MAX];
template<class T>
class simpleBIT
{
	T *tree;
	int maxVal;
	public:
	simpleBIT(int N)
	{
		tree = new T[N+1];
		memset(tree,0,sizeof(T)*(N+1));
		maxVal = N;
	}
	void update(int idx,T val)
	{
		while(idx <= maxVal)
		{
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}
	
	T query(int idx)
	{
		T sum = 0;
		while(idx > 0)
		{
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	
	T readSingle(int idx)
	{
		T sum = tree[idx];
		if(idx > 0)
		{
			int z = idx - (idx & -idx);
			idx--;
			while(idx != z)
			{
				sum -= tree[idx];
				idx -= (idx & -idx);
			}
		}
		return sum;
	}

	~simpleBIT(){
		delete(tree);
	}
};

LL small[MAX];
int main()
{_
	int t,n,cases=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		simpleBIT<LL> b(100010);
		for(int i=0;i<n;i++){
			cin>>arr[i];
			small[i] = b.query(arr[i]);
			b.update(arr[i],1);
		}
		
		simpleBIT<LL> b2(100010);
		LL ans = 0;
		for(int i=n-1,k=0;i>=0;i--,k++){
			LL temp = k - b2.query(arr[i]);
			ans = (ans + (temp*(temp-1))/2)%MOD;
			ans = (ans - temp*small[i] + MOD)%MOD;
			b2.update(arr[i],1);
		}

		cout<<ans<<endl;
	}
	return 0; 
}
