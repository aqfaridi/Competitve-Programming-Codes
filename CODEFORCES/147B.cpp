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

int col[100],arr[100][100];
int a[100],b[110],c[110],d[110];
map<int,pair<int,int> > m;
int main()
{
    ios::sync_with_stdio(false);
    int row;
    cin>>row;
    for(int i=1;i<=row;i++)  cin>>col[i];
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col[i];j++)
        {
            cin>>arr[i][j];
            m[arr[i][j]] = make_pair(i,j);
        }

    int idx = 0;
    map<int,pii>::iterator it = m.begin();
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col[i];j++)
        {
           int vl = arr[i][j];
           if(it->first == vl){it++;continue;}
           pii p1 = it->second;
           pii p2 = m[vl];

           a[idx] = p2.first;
           b[idx] = p2.second;
           c[idx] = p1.first;
           d[idx] = p1.second;
           
           int newi = p1.first;
           int newj = p1.second;
           swap(arr[i][j],arr[newi][newj]);
           m[it->first] = p2;
           m[vl] = p1;
           idx++;
           it++;
        }

    cout<<idx<<endl;
    for(int i=0;i<idx;i++){cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<endl;
    }
    return 0;
}


            
