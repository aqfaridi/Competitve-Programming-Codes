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
#define MAX 1010
#define MOD 1000000007
vector<int> arr;
map<LL,int> check;
LL A[MAX],B[MAX],mem[MAX][MAX];
int n,m,r,k,two,three,four,ltwo,lthree,lfour;
vector<LL> unq;
bool checkin(LL node){

	if(node == 1 || node == n || node == 2*n+1 || node == 3*n)
		return check[node] < 1;
	else if(node > n+1 && n < 2*n)
		return check[node] < 3;
	else
		return check[node] < 2;

}
LL solve(int idx,int cnt){
	if(idx == n){
		if(cnt >= (m-k))
			ltwo + lthree 

	LL& res = mem[idx][cnt];
	if(res !=  -1)	return res;

	res = solve(idx+1,cnt);
	if(checkin(A[idx]) && checkin(B[idx])){
		check[A[idx]]++;
		check[B[idx]]++;
		res = (res + solve(idx+1,cnt+1))%MOD;
	}

	return res;
}
int main()
{_
	cin>>n>>m>>r;
	for(int i=0;i<m;i++){
		cin>>A[i]>>B[i];
		unq.pb(A[i]);
		unq.pb(B[i]);
	}
	uniq(all(unq));
	int size = unq;

	for(int i=0;i<size;i++){
		int node = unq[i];
		if(node == 1 || node == n || node == 2*n+1 || node == 3*n)
			two++;
		else if(node > n+1 && n < 2*n)
			four++;
		else
			three++;
	}

	ltwo = 4 - two;
	lfour = n-2 - four;
	lthree = 2*n - 2 - three;

	while(r--){
		cin>>k;
		memset(mem,-1,sizeof mem);
		check.clear();
		LL ans = solve(0,0);
		cout<<ans<<endl;
	}


	return 0; 
}
