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
int a[110][110];
int LCS(string s1 , string s2 , int l1 , int l2)
{
    memset(a , 0 ,sizeof(a)) ;
    for(int i = 1 ; i <= l1 ; i++)
    {
            for(int j = 1 ; j <= l2 ; j++)
            {
                    if(s1[i-1] == s2[j-1])
                    {
                               a[i][j] = a[i-1][j-1] + 1 ;
                    }
                    else
                    {
                               a[i][j] = max( a[i-1][j] , a[i][j-1] ) ;
                    }
            }
    }
    return a[l1][l2] ;
}
int main()
{
    ios::sync_with_stdio(false);
    string s,t;
    cin>>s;
    cin>>t;
    int ls = s.length();
    int lt = t.length();
    if( ls < lt)
        cout<<"need tree"<<endl;
    else
    {
        if(LCS(s,t,ls,lt) == lt && lt != ls)
            cout<<"automaton"<<endl;
        else
        {    
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if(s == t)
                cout<<"array"<<endl;
            else if(LCS(s,t,ls,lt) < lt)
                cout<<"need tree"<<endl;
            else
                cout<<"both"<<endl;
        }
    }
    return 0; 
}
