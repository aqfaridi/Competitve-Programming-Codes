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

#define MAX 1010
#define MOD 1000000007
double mem[MAX][MAX];
double solve(int w,int b)
{
    if(w <= 0)  return 0;//no way to win now
    if(b <= 0)  return 1;//now white will definitely come
    double& res = mem[w][b];
    if(res != -1)   return res;
    res = 0;

    //1st turn : may be white or black mice
    res = (1.0*w)/(w+b);           //white
    double cont_prob = (1.0*b)/(w+b); //black : now we have to continue turns

    b--;
    //probability of continuing after opponent turn 
    cont_prob *= (1.0*b)/(w+b);  //must be black
    b--;

    //now mice jumped can be white or black in next turn;
    if(w+b > 0)
    {
        double white = (1.0*w)/(w+b) * solve(w-1,b);
        double black = (1.0*b)/(w+b) * solve(w,b-1);
        res += cont_prob*(white+black);
    }

    return res;    
}
int main()
{
    int w,b;
    cin>>w>>b;
    for(int i=0;i<=w;i++) for(int j=0;j<=b;j++)     mem[i][j] = -1;
    printf("%.9lf",solve(w,b));
    return 0; 
}
