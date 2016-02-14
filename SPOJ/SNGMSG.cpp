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

#define MAX 100010
#define MOD 1000000007

int main()
{
    ios::sync_with_stdio(false);
    int t,l,len,cnt,num;
    string n,str,ans;
    cin>>t;
    while(t--)
    {
        ans = "";
        cin>>n;
        cin>>str;
        len = n.ln;
        l = str.ln;
        cnt = 0;
        rep(i,l)
        {
            if(i%len == 0)    cnt++;
            if(cnt & 1)
            {
                num = (str[i]-'a') - (n[i%len]-'0');
                ans += ('a' + ((num < 0)?26+num:num) );
            }
            else
            {
                num = (str[i]-'a') - (n[len-1-i%len]-'0');
                ans += ('a' + ((num < 0)?26+num:num));
            }
        }
        cout<<ans<<endl;
    }
    return 0; 
}
