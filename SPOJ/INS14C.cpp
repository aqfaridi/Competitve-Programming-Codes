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
int pos[1010];
int main()
{
    ios::sync_with_stdio(false);
    int t,l,cnt,K,ones,zeros;
    string str,sub;
    cin>>t;
    while(t--)
    {
        cnt = 0;
        cin>>l>>K;
        ones = (l-K+1)/2;
        zeros = (l-K)/2;
        cin>>str;
        if(l==1 && K==1)
        {
            cout<<str<<endl;
            continue;
        }
        
        sub = "";

        for(int i=0;i<l;i++)
        {            
            if(str[i] == '1' && cnt < ones)
            {
                cnt++;
                continue;
            }            
            sub += str[i];
        }
        //trace2(cnt,ones);
        if(cnt < ones)
        {
            //our ans is 0s
            rep(i,K)
                cout<<0;
            cout<<endl;

            continue;
        }
        //cout<<sub<<endl; 
        l = sub.length();
        cnt = 0;
        str = "";
        for(int i=0;i<l;i++)
        {
            if(cnt < zeros && sub[i] == '0')
            {
                cnt++;
                continue;
            }
            str += sub[i];
        }
        if(cnt < zeros)
        {
            rep(i,K)
                cout<<1;
            cout<<endl;
            continue;
        }
        cout<<str<<endl;
    }
    return 0; 
}
