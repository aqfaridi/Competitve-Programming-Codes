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

int main()
{
    ios::sync_with_stdio(false);
    int x1,x2,y1,y2,d;
    cin>>x1>>y1>>x2>>y2;
    if(x2 == x1){
        d = abs(y2-y1);
        cout<<(x1+d)<< " " << (y1) << " " << (x2+d)<<" " << (y2) << endl;
    }
    else if(y1 == y2){
        d = abs(x2-x1);
        cout<<x1<< " " << y1+d << " " << x2 << " " << y2+d <<endl;
    }
    else{
    if(abs(x2-x1) != abs(y2-y1))
    {
        cout<<-1<<endl;return 0;
    }
       int xx = min(x1,x2);
       int yy = min(y1,y2);
       int xxx = max(x1,x2);
       int yyy = max(y1,y2);
       if(y1 > y2){
           d = y1-y2;
           cout<< x1 << " " << y1-d << "  " << x2 << " " << y2+d << endl ;
       }
       else{
           cout<<xx<<" " << yyy<<" " << xxx<< " " << yy <<endl;
        }
    }
    return 0; 
}
