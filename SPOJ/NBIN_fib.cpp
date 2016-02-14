#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
LL fib[80],arr[80];
void precalc()
{
    fib[0] = 1,fib[1] = 2, fib[2] = 3;
    for(int i=3;i<80;i++)
        fib[i] = fib[i-1] + fib[i-2];
}
int main()
{
    precalc();
    ios::sync_with_stdio(false);
    int t;
    string str;
    LL n,idx,sum,k,kk;
    cin>>t;
    while(t--)
    {
        cin>>n;
        str = "";
        sum = k = kk =0;
        idx = upper_bound(fib,fib+80,n) - fib;
        idx -= 1;
        for(int i=idx;i>=0;i--)
        {
            if(sum + fib[i] <= n)
            {
                sum += fib[i];
                arr[k++] = i;
            }
        }
        kk = 0;
        for(int i=arr[kk];i>=0;i--)
        {
            if((kk < k) && i == arr[kk])
            {
                str += "1";
                kk++;
            }
            else 
                str += "0";
        }
        cout<<str<<endl;
    }
    return 0; 
}
