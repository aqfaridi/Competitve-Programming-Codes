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

#define MAX 1010
#define MOD 1000000007
string str[MAX];
int num[MAX],perm[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int diff,t,m,p;
    cin>>t;
    while(t--)
    {
        cin>>m>>p;
        diff = INT_MAX;
        for(int i=0;i<m;i++)
            cin>>str[i];
        
        for(int i=0;i<p;i++)
            perm[i] = i;


       do{
           memset(num,0,sizeof(num));
           for(int i=0;i<m;i++)
           {
                for(int j=0;j<p;j++)
                    num[i] = num[i]*10 + (str[i][perm[j]]-'0'); 
                //cout<<num[i]<<" ";
           }
           //cout<<endl;

           diff = min(diff,*max_element(num,num+m) - *min_element(num,num+m));
       }
       while(next_permutation(perm,perm+p));
        

        cout<<diff<<endl;
    }
    return 0; 
}
