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

#define MAX 100010
#define MOD 1000000007
int valid[] = {1,4,7,16,19,25,28,31};
int n,row,col;
int mem[20010][32][32];
int rec(int idx,int mask,int info)
{
    if(idx == n)
        return (info==0);
    
    int& res = mem[idx][mask][info];
    if(res != -1)   return res;

    res = 0;

    for(int i=0;i<=7;i++)
    {
        bool isValid = true;
        for(int j=0;j<=4;j++)
        {            
            if((info & (1<<j)) && (valid[i] & (1<<j))==0)
            {       
                isValid = false;
                break;
            }
            if(j == col && row == idx+1)
            {
                if((info & (1<<j))==0 && (valid[i] & (1<<j)))
                {
                    isValid = false;
                    break;
                }
            }
            if(row == idx && j == col)
            {
                if( (valid[i] & (1<<j)) == 0)
                {
                    isValid = false;
                    break;
                }
            }
        }

        if(isValid)
        {
            if(row == idx)
                res = (res + rec(idx+1,valid[i],((info^valid[i]) & ~(1<<col))))%MOD;
            else
                res = (res + rec(idx+1,valid[i],(info ^ valid[i])))%MOD;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    char ch;
    cin>>t;
    while(t--)
    {
        cin>>n>>ch>>row;
        col = ch-'A';
        row -= 1;
        memset(mem,-1,sizeof mem);
        cout<<rec(0,0,0)%MOD<<endl;
    }
    return 0; 
}