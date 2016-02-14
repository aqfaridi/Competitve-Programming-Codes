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
typedef pair< pii , int > tri;
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
int mat[50][50];
int n,start_i,start_j,end_i,end_j;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
void solve(int i,int j)
{
    int x,y,cnt;
    queue< tri > q;
    q.push(mp(mp(i,j),0));
    while(!q.empty())
    {
        x = q.front().first.first;
        y = q.front().first.second;
        cnt = q.front().second;
        q.pop();

        if( x < 0 || y < 0 || x >= n || y >= n) continue;
        
        //trace3(x,y,cnt);
        if(x == end_i && y == end_j)    break; 
       
        for(int i=0;i<=3;i++)
            if(mat[x+dx[i]][y+dy[i]] == 1)
            {
                q.push(mp(mp(x+dx[i],y+dy[i]),cnt+1));
                mat[x+dx[i]][y+dy[i]] = 0;
            }
    }
    cout << cnt << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    char ch;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>ch;
            if(ch == 'P')
                mat[i][j] = 1;
            else if(ch == 'T')
                mat[i][j] = 0;
            else if(ch == 'S')
            {
                mat[i][j] = -1;
                start_i = i;start_j = j;
            }
            else if(ch == 'E')
            {
                mat[i][j] = 1;
                end_i = i;end_j = j;
            }
        }
    solve(start_i,start_j);

    return 0; 
}
