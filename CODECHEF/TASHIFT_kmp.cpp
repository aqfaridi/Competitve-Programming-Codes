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

#define MOD 1000000007

namespace KMP
{
    #define MAX 3000010
    int b[MAX],m,n,maxx=0,pos=0;
    void LPS(string pat)
    {
        int i=0,j=-1;//j => border
        m = pat.length();
        b[i] = j;
        while(i<m)
        {
            while(j>=0 && pat[i]!=pat[j]) j=b[j];//next widest border
            i++;j++;
            b[i] = j;
        }
    }
    void kmpSearch(string txt,string pat)
    {    
        int i=0,j=0;
        n = txt.length();
        while(i<n)
        {
            while(j>=0 && txt[i]!=pat[j]) j=b[j];//next widest border of some prefix of pat
            i++;j++;
            if(j > maxx)
            {
                maxx = j;
                pos = (i-j);
            }
        }

    }
}
using namespace KMP;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    string A,B;
    cin>>n;
    cin>>A>>B;
    LPS(A);
    B = B+B;
    kmpSearch(B,A);
    cout<<pos<<endl;
    return 0; 
}
