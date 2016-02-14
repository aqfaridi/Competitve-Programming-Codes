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
#include <climits>
#define MAX 100010
#define MOD 1000000007
int board[18],temp[18],row,col,minn;
int a[500],b[500],t_a[500],t_b[500];
int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,-1,0,1};
void flip(int x,int y)
{
    for(int i=0;i<5;i++)
    {
        int nx = x+dx[i],ny = y+dy[i];
        if(nx >= 0 && nx < col && ny >= 0 && ny < row)
            temp[nx] ^= (1<<ny);
    }
}
int solve(int profile)
{
    int cnt = 0,k=0;
    for(int i=0;i<col;i++)
        temp[i] = board[i];

    for(int j=0;j<row;j++)
        if(profile&(1<<j))
        {
            flip(0,j);
            t_a[k] = 0;t_b[k++] = j;
            cnt++;
        }
    for(int i=1;i<col;i++)
        for(int j=0;j<row;j++)
            if((temp[i-1] & (1<<j)) ==0)
            {
                //trace3(i,temp[i-1],j);
                flip(i,j); 
                t_a[k] = i;t_b[k++] = j;
                cnt++;
            }
    
    if(temp[col-1] == ((1<<row)-1))
        return cnt;
    else
        return INT_MAX;
    
}
string str[16];
int main()
{
    ios::sync_with_stdio(false);
    int ret;
    while(1)
    {
        cin>>col>>row;
        if(col == 0 && row == 0)    break;
        
        for(int i=0;i<row;i++)
            cin>>str[i];
        
        memset(board,0,sizeof(board));
        for(int j=0;j<col;j++)
            for(int i=0;i<row;i++)
            {
                if(str[i][j] == '1')
                    board[j] |= (1<<i);
            }

        minn = INT_MAX;
        for(int i=0;i<(1<<row);i++)
        {
            ret = solve(i);
            if(ret < minn)
            {
                minn = ret;
                for(int j=0;j<ret;j++)
                    a[j] = t_a[j],b[j] = t_b[j];
            }
        }

        if(minn != INT_MAX)
        {
            cout<<minn<<endl;
            for(int i=0;i<minn;i++)
                cout<<a[i]+1<<" "<<b[i]+1<<endl;
        }
        else
            cout<<-1<<endl;
        
    }
    return 0; 
}
