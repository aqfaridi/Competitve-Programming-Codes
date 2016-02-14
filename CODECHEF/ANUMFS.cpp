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
LL x[5020],y[5020];
LL R[100],C[100];
int mark[5020];
int main()
{
    ios::sync_with_stdio(false);
    LL t,n,m,maxx,cost,xx,yy,idx;
    LL total,id;
    bool f;
    string str;
    t = 1;
    while(t--)
    {
        cin>>n;
        rep(i,n)    cin>>x[i]>>y[i];        
        cin>>m;
        id = cost = total = 0;
        rep(i,m) 
        {
            cin>>R[i]>>C[i];
            if(C[i] > cost)
            {
                id = R[i];
                cost = C[i];
            }
        }
        
        f = false;
        idx = rand()%n;
        mark[idx] = 1;

        total += 2*(x[idx]+y[idx])*cost;
        int cn=1;
      
            rep(i,n)
            {
                cout<<id<<" "<<x[idx]<<" "<<y[idx]<<endl;
                fflush(stdout);
                cin>>str;
                if(str == "yes")
                {
                    xx = x[idx];yy = y[idx];
                    f = true;
                    break;
                }

                while(1)
                {
                    idx = rand()%n;
                    if(mark[idx] == 0)
                        break;
                    if(cn==n) break;
                }
                if(cn == n)
                    break;
                mark[idx] =  1;
                cn++;
                
                total += 2*(x[idx]+y[idx])*cost;

                if(total > 1000000000)
                    break;
            }
        
         
        if(f)
            cout<<-1<<" "<<xx<<" "<<yy<<endl;
        else
            cout<<-1<<" "<<-1<<" "<<-1<<endl;
    }
    return 0; 
}
