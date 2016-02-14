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
int mem[100][100];
int solve(int sum,int d)
{
    if(sum == 13)    return 1;
    if(d == 0)  return 0;

    int& res = mem[sum][d];
    if(res != -1)   return res;
    res = 0;

    for(int i=0;i<10;i++)
        res += solve(sum+i,d-1);
    return res;
}
int cnt[] = {6,69,405,1725,6027,18312,50016,125445};
int main()
{
    ios::sync_with_stdio(false);
    /*
    for(int i=2;i<=9;i++)
    {
        memset(mem,-1,sizeof mem);    
        cout << solve(0,i) <<",";
    }
    
    
    int cn = 0;
    for(int i=10000;i<100000;i++)
        if(i%10 + (i/10)%10 + (i/100)%10 + (i/1000)%10 + (i/10000)%10 == 13)
            cn++;
    cout<<cn<<endl;
    */
    int t,n,i,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0){
            cout<<0<<endl;
            continue;
        }
        sum = 0;
        for(i = 0;i<=6;i++)
        {
            sum += cnt[i];
            n -= cnt[i];
            if(n <= 0)
                break;
        }
        cout<<i+2<<endl;
    }


    return 0; 
}
