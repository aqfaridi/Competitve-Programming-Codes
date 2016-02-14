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

#define MAX 2520
#define MOD 1000000007
int main()
{
    ios::sync_with_stdio(false);
    LL t,n,pro,i,j,sqr;
    LL cnt,sum;
    cin>>t;
    while(t--)
    {
        cnt = 0;
        cin>>n;
        i=1;
        while(i<n)
        {
            sum = 0;
            j = n-i;
            pro = (i*j-1);      
            sqr = (int)sqrt(pro);
            for(int z=1;z<=sqr;z++)
                sum += ((pro/z - z)*2 + 1); 
            cnt += sum;
            i++;
        }
        cout<<cnt<<endl;
    }
    return 0; 
}
