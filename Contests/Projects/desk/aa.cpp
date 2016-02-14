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
int main()
{
    ios::sync_with_stdio(false);
  int t,n,color;
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
            cin>>arr[i];
     
     int cnt = 0;
     init[0] = 0;
     //cout<<init[0]<<" ";
     for(int i=1;i<=n;i++)
     {
         color = (arr[i] >= 1000);
         if(color != init[i-1]){
            cnt++;
            init[i] = color;
         }
         else
            init[i] = init[i-1];
            
        //cout<<init[i]<<" ";
     }
     
    if(init[n] == 1)
        cout<<"blue ";
    else
        cout<<"grey ";
    cout<<cnt<<endl;
      
  }



    return 0; 
}