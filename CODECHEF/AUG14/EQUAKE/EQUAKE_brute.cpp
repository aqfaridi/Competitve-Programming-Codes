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
int input[8*MAX];
int rt[8*MAX][12];
int pwr[] = {1,10,100,1000,10000};
vector<int> dg;
int main()
{
    ios::sync_with_stdio(false);
    int t,d,num,n,q,type,maxx,l,r,f;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>input[i];
        d = log10(input[i])+1;
        rep(j,d)
           dg.pb((input[i]/pwr[j])%10);
        reverse(dg.begin(),dg.end());
        rt[i][0] = input[i];
        for(int j=1;j<d;j++){
           num = 0;
           rotate(dg.begin(),dg.begin()+1,dg.end());
           rep(k,d)
               num = num*10 + dg[k];
           rt[i][j] = num;
           //cout<<num<<endl;
        }
        for(int j=d;j<=11;j++)
            rt[i][j] = rt[i][j%d];
        dg.clear();
    }

    /*
    rep(i,n){
        rep(j,12)
            cout<<rt[i][j]<<endl;
        cout<<"-------------"<<endl;
    }*/

    cin>>q;
    while(q--)
    {
        cin>>type;
        if(!type){
            cin>>l>>r>>f;
            l+=1; r+=1;
            for(int i=l;i<=r;i++)
                rotate(rt[i],rt[i]+f,rt[i]+12);
        }
        else{
            cin>>l>>r;
            l+=1; r+=1;
            maxx = 0;
            for(int i=l;i<=r;i++)
                maxx = max(maxx,rt[i][0]);
            cout<<maxx<<endl;
        }
    }
    return 0; 
}
