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
#include <climits>
#include <cassert>

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
LL ar[MAX];
int min(int a,int b)
{
    return (a>b)?b:a;
}
int main()
{
    ios::sync_with_stdio(false);
    LL n,a,b,a1,b1;
    cin>>n>>a>>b;
    if(a*b >= 6*n)
    {
        cout<<a*b<<endl;
        cout<<a<<" "<<b<<endl;
        return 0;
    }
    else if((6*n)%a == 0)
        b = (6*n)/a;
    else if((6*n)%b == 0)
        a = (6*n)/b;
    else
    {
        while(a*b <  6*n)
        {
            a1 = (a+1);
            b1 = (b+1);
                if(a1*b == 6*n)
                {
                    a = a1; break;
                }
                else if(a*b1 == 6*n)
                {
                    b = b1;break;
                }
            if(a1*b > a*b1)
             b++;
            else
               a++;

        }
    }
    cout<<a*b<<endl;
    cout<<a<<" "<<b<<endl;


    return 0; 
}
