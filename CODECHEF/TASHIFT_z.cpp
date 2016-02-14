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

#define MAX 3000010
#define MOD 1000000007

int z[MAX];
void z_algorithm(string s)
{
    int L=0,R=0,n = s.length();
    z[0] = n;

    for(int i=1;i<n;i++)
    {
        if(i > R){   // case 1 - brute
            L = R = i;
            while(R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        }
        else{
            int k = i-L;
            if(z[k] < R-i+1)    z[i] = z[k]; //2a
            else{              //2b & 2c  -brute
               L = i;           //beta = R-i (0-based)
               while(R < n && s[R-L] == s[R]) R++;
               z[i] = R-L; R--;                
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    string a,b,s;
    cin>>n;
    cin>>a>>b;
    s = a + '$' + b + b;
    z_algorithm(s);
    int l = 3*n+1,pos=0,maxx=0;
    for(int i=n+1;i<l;i++)
    {
        //trace1(z[i]);
        if(z[i] > maxx) // LCP of rotation at (i-n-1)th index        
        {
            //trace2(z[i],maxx);
            maxx = z[i]; 
            pos = i-n-1;
        }
    }
    cout<<pos<<endl;
    return 0; 
}
