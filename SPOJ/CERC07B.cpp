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
int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,-1,0,1};
int minn,row,col;
int board[20],temp[20];
void flip(int x,int y)
{
    for(int i=0;i<5;i++)
    {
        int nx = x+dx[i],ny = y+dy[i];   
        if(nx >=0 && nx < row && ny >=0 && ny < col)
            temp[nx] ^= (1<<ny);
    }
}

int solve(int profile)
{
   int cnt = 0;

   for(int i=0;i<row;i++)
       temp[i] = board[i];

   //flips for first row
   for(int j=0;j<col;j++)
       if((profile&(1<<j))==0)
       {
           cnt++;
           flip(0,j);
       }

   //flips to make prev row all bit set
   for(int i=1;i<row;i++)
   {
       for(int j=0;j<col;j++)
        if((temp[i-1]&(1<<j))==0)
        {
            flip(i,j);
            cnt++;
        }
   }
   //trace3(profile,temp[row-1],cnt);
   if(temp[row-1] == ((1<<col)-1))
        return cnt;
   else 
       return INT_MAX;
}

string str[20];
int main()
{
    ios::sync_with_stdio(false);
    while(1)
    {
        cin>>row>>col;
        if(col == 0 && row == 0)    break;

        for(int i=0;i<row;i++)
            cin>>str[i];
        
        memset(board,0,sizeof(board));
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(str[i][j] == '.')
                    board[i] |= (1<<j);
            }

        minn = INT_MAX;
        for(int i=0;i < (1<<col);i++)    
            minn = min(minn,solve(i));
        
        if(minn == INT_MAX)
            cout<<"Damaged billboard."<<endl;
        else
            cout<<"You have to tap "<<minn<<" tiles."<<endl;
    }
    return 0; 
}
