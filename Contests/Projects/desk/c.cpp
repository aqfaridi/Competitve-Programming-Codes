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

#define MAX 10010
#define MOD 1000000007
int arr[MAX],init[MAX];
int sod(int n)
{
    int sum = 0;
    while(n>0)
    {
        sum += n%10;
        n/=10;
    }
    return sum;
    
}
int main()
{
    ios::sync_with_stdio(false);
  int t;
  LL n,D,sD,x;
  cin>>t;
  while(t--)
  {
      cin>>n;
    x = -1;
    for(LL b=1;b<=162;b++)
    {
         D = b*b + 4*n;
         sD = sqrt(D);
         if(sD*sD == D)
         {
             if((sD-b) > 0 && (sD-b)%2==0 && sod( (sD-b)/2 ) == b )
             {
                 x = (sD-b)/2;
                 break;
             }
             
         }
        
    }
    cout<<x<<endl;
      
  }



    return 0; 
}