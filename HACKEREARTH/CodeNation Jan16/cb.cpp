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
#define MOD 1000000007
int arr[20];
LL fl[1000010];
int a[MAX];
void factorsieve()
{
        for(int i=1;i<MAX;i++)
                    a[i]=i;
 
        for(int i=2;i*i<=MAX;i++)
        {
           if(a[i] == i)
           {
                for(int j=i*i;j<MAX;j+=i)
                {
                      if(a[j] == j)
                      {
                             a[j]=i;
                      }
                 }
           }
 
        }
}

map<int,int> mapp;
void pre(){
	fl[0] = fl[1] = 0;
	fl[2] = 1;
	int n;
	for(int i=3;i<1000001;i++){
        fl[i] = fl[i-1];
        n=i;
        int temp=a[n];
        n/=a[n];
        int count=1;
        while(a[n]!=1)
        {
            if(temp == a[n])
                count++;
            else
            {
                fl[i] += count;
                temp = a[n];                
                count=1;
            }
            n/=a[n];
        }
        fl[i] += count;
	
	}

}
int main()
{_
	factorsieve();
	pre();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	LL sum = 0,ans = 0;
	for(int i=0;i<(1<<n);i++){
		sum = 0;
		for(int j=0;j<n;j++)
			if(((1<<j)&i))
				sum += fl[arr[j]];
		if(!(sum&1))
			ans += sum;
	}

	cout<<ans<<endl;	
	return 0; 
}
