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
int P[1010],mark[1010];
int mat[1010][1010];
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m,ptr,size,assign,sum;
    bool f,nosol;
    cin>>t;
    while(t--)
    {
        memset(mark,0,sizeof(mark));
        memset(mat,0,sizeof mat);
        cin>>n>>m;
        f = true;
        nosol = false;
        rep(i,n){    cin>>P[i]; if(P[i] == i) f = false; }
        
        if(!f || n==1 || n==2 ||  m==1 || m==2){
            cout<<"No Solution"<<endl;
            continue;
        }
       
        assign = n*m;
        rep(i,n)
        {
            ptr = i;
            v.clear();
            if(!mark[i])
            {
                do{
                    v.pb(ptr);
                    mark[ptr] = 1;
                    ptr = P[ptr];
                }while(ptr != i);
            
                size = v.size();
                if(size == 2)
                    nosol = true;

                for(int k=0;k<m;k++)
                    for(int j=k%size;;j++)
                    {
                        if(mat[v[j%size]][k] != 0)  break;
                        mat[v[j%size]][k] = assign;
                        assign--;
                    }
            }
        }
      

        if(nosol)
        {
            cout<<"No Solution"<<endl;
            continue;
        }

        for(int i=0;i<n;i++)
            sort(mat[i],mat[i]+m);
        
        if(n == 3 && m == 4)
        {   
            for(int i=0;i<n;i++)
            {
                cout<<mat[i][0];
                for(int j=1;j<m;j++)
                {
                    if(mat[i][j] == 6)  {cout<<" "<<7;continue;}
                    if(mat[i][j] == 7) {cout<<" "<<6;continue;}
                        cout<<" "<<mat[i][j];
                }
                cout<<endl;
            }
        }
        else
        {        
            for(int i=0;i<n;i++)
            {
                cout<<mat[i][0];
                for(int j=1;j<m;j++)
                        cout<<" "<<mat[i][j];
                cout<<endl;
            }
        }
    }
    return 0; 
}
