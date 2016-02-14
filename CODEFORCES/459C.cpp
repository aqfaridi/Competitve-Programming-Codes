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
int mat[MAX][MAX];//d*n
int a[MAX],k,n,d,x;
void recurse(int idx)
{
    if(x == n)
        return;

    if(idx == d)
    {
        for(int i=0;i<d;i++)
            mat[i][x] = a[i];
        x++;

        return;
    }
    
    for(int i=1;i<=k;i++)
    {
        a[idx] = i;
        if(x < n)
            recurse(idx+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
   
    cin>>n>>k>>d;  
    LL pro = 1;
    for(int i=0;i<d;i++)
    {
        if(pro > n)
            break;
        pro = pro*k;
    }

    if(pro < n)
    {
        cout<<-1<<endl;
        return 0;
    }

    if( k > 3010)
        k = 3010;

    recurse(0);
    
    for(int i=0;i<d;i++){
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl; 
    }

    return 0; 
}
