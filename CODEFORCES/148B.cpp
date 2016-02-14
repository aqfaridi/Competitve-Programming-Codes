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
int cnt[10];
int main()
{
    ios::sync_with_stdio(false);
    int n,q,x,y,dp;
    cin>>n>>q;
    string str,s;
    cin>>str;
    int l = str.length();
    while(q--)
    {
        dp = 1;
        memset(cnt,0,sizeof(cnt));
        s = str;
        cin>>x>>y;x--;y--;
        int c = 0;
        for(int i=x;i>=x && i <= y && c<=(y-x)*10;i+=dp,c++)
        {
            if(s[i] == 'a')
            {
                
                if(i == x && dp == -1) break;
                if(i == y && dp == 1) break;
                continue;
            }

            if(s[i] == '>')
            {
                cout<<i<<" >"<<endl;
                dp = 1;
                if(i-1 >= x && (s[i-1] == '>' || s[i-1] == '<'))
                    s[i-1] = 'a';

                if(i==y && dp == 1)    break;
            }
            if(s[i] == '<')
            {
                cout<<i<<" <"<<endl;
                dp = -1;
                if(i-1 >= x && (s[i-1] == '>' || s[i-1] == '<'))
                    s[i-1] = 'a';
            }
            
            if(s[i] >= 48 && s[i] <=57){
                cout<<i<<" "<<s[i]<<endl; 
                cnt[s[i]-'0']++;
                if((int)s[i] - 1 >= 0)
                    s[i] = (s[i] - 1);
                else
                    s[i] = 'a';

                if(i == x && dp == -1) break;
                if(i == y && dp == 1) break;
            }
         }
        for(int i=0;i<=9;i++)
            cout<<cnt[i]<<" ";
        cout<<endl;
    }
    return 0; 
}
