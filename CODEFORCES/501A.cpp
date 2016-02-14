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
typedef pair< int, pii > tri;

typedef vector<int> array;
typedef vector<LL> array_LL;
typedef vector<vector<int> > matrix;
typedef vector<vector<LL> > matrix_LL;


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

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
LL score(LL p,LL t){
    return max(3*(p/10) , p - (p/250) *t);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    LL a,b,c,d;
    cin>>a>>b>>c>>d;
    LL s1 = score(a,c);
    LL s2 = score(b,d);
    if(s1 > s2)
        cout<<"Misha"<<endl;
    else if(s2 > s1)
        cout<<"Vasya"<<endl;
    else
        cout<<"Tie"<<endl;
        
    return 0; 
}

