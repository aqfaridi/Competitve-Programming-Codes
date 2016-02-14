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

#define MAX 50
#define MOD 1000000007
bool f = false;
char ans;
int n;
string str[MAX];
void DFS(int i,int j,char ch,int cnt)
{
    if(str[i][j] == '.')
        return;
    if(j+2 < n && str[i][j] == str[i][j+1] && str[i][j+1]==str[i][j+2])
    {
        f = true;
        ans = ch;
        return ;
    }
    if(j-2 > 0 && str[i][j] == str[i][j-1] && str[i][j-1] == str[i][j-2])
    {
        f = true;
        ans = ch;
        return;
    }
    if(i-2 > 0 && str[i][j] == str[i-1][j] && str[i-1][j] == str[i-2][j])
    {
        f = true;
        ans = ch;
        return;
    }
    if(i+2 < n && str[i][j] == str[i+1][j] && str[i+1][j] == str[i+2][j])
    {
        f = true;
        ans = ch;
        return;
    }

    if(i-2 > 0 && j-2 > 0 && str[i][j] == str[i-1][j-1] && str[i-1][j-1] == str[i-2][j-2])
    {
        f = true;
        ans = ch;
        return;
    }
    if(i+2 < n && j+2 < n && str[i][j] == str[i+1][j+1] && str[i+1][j+1] == str[i+2][j+2])
    {
        f = true;
        ans = ch;
        return ;
    }
    if(i-2 > 0 && j+2 < n && str[i][j] == str[i-1][j+1] && str[i-1][j+1]==str[i-2][j+2])
    {
        f = true;
        ans = ch;
        return ;
    }
    if(i+2 > 0 && j-2 > 0 && str[i][j] == str[i+1][j-1] && str[i+1][j-1] == str[i+2][j-2])
    {
        f = true;
        ans = ch;
        return ;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int l;
    bool f2 = false;
    cin>>n;
    rep(i,n)
        cin>>str[i];
    rep(i,n)
    {
        rep(j,n)
        {
            DFS(i,j,str[i][j],1);
            if(f && ans != '.')
            {
                cout<<ans<<endl;
                f2 = true;
                break;
            }
        }
        if(f2)
            break;
    }
    if(!f2)
        cout<<"ongoing"<<endl;
    return 0; 

}
