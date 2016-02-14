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
    

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define debug                       if(1)
#define debugoff                    if(0)    

#define MAX 100010
#define MOD 1000000007
LL arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    LL v,cnt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        rep(i,n)
            cin>>arr[i];
        v = arr[0]; 
        cnt = 0;
        rep(i,n)
        {
            if(v < arr[i])
            {
                cnt += (arr[i] - v);
                v += (arr[i] - v);
            }
            v -= 1;
        }

        cout<<arr[0] + cnt<<endl;
    }
    return 0; 
}
