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

int main()
{
    ios::sync_with_stdio(false);
    int na,ma,nb,mb;
    char ch ;
    int a[60][60];
    int b[60][60];
    cin>>na>>ma;
    for(int i=0;i<na;i++)
        for(int j=0;j<ma;j++){
            cin>>ch;
            a[i][j] = ch-48;
        }
    cin>>nb>>mb;
    for(int i=0;i<nb;i++)
        for(int j=0;j<mb;j++){
            cin>>ch;
            b[i][j] = ch-48;
        }
    int sum = 0,maxx = -1 , xx = INT_MIN , yy = INT_MIN;
    for(int x=-50;x<=50;x++){
        for(int y=-50;y<=50;y++){
            sum = 0;
            for(int i=0;i<na;i++){
                for(int j=0;j<ma;j++){
                    if(i+x>=0 and i+x<nb   and j+y>=0 and j+y<mb){
                        sum += a[i][j]*b[i+x][j+y];
                    }
                }
            }
            if(sum > maxx){
                maxx = sum;
                xx= x;
                yy = y;
            }
        }
    }
    if(xx == INT_MIN)
           cout<<-1<<endl;
    else
        cout<<xx<<" " << yy << endl;
    return 0; 
}
