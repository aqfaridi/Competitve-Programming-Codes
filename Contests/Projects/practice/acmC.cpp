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
vector<int> v[10];
void pre(){
    v[0].pb(8);
    v[1].pb(0);
    v[1].pb(3);
    v[1].pb(4);
    v[1].pb(7);
    v[1].pb(8);
    v[1].pb(9);

    v[2].pb(2);
    v[2].pb(8);

   v[3].pb(8);v[3].pb(9);
   v[4].pb(8);v[4].pb(9);
   v[5].pb(6);v[5].pb(8);v[5].pb(9);
   v[6].pb(8);
   v[7].pb(0);v[7].pb(3);v[7].pb(8);v[7].pb(9);
   v[8].pb(8);v[9].pb(8);v[9].pb(9);
}
int main()
{
    pre();
    ios::sync_with_stdio(false);
    int t;
    string s,m,ss,sss;
    cin>>t;
    while(t--)
    {
        cin>>s>>m;
        ss = s;
        int lm = m.length();
        int ls = s.length();

        bool b = false;
        if(ls == lm){
            for(int i=0;i<ls;i++){

                if(b)
                    ss[i] = v[s[i]-'0'][v[s[i]-'0'].size()-1] + '0';
                
                if(!b)
                for(int j=0;j<v[s[i]-'0'].size();j++){           
                    if(v[s[i]-'0'][j] <= (m[i]-'0')){                       
                        ss[i] = v[s[i]-'0'][j] + '0';
                        if(v[s[i]-'0'][j] < m[i]-'0')
                            b = true;
                    }
                }
                
            }

            cout<<ss<<endl;
            continue;
        }
       
        ss = m;
        sss = m;
        int cnt = 0;
        for(int i = lm-1,k=ls-1;i>=lm-ls;k--,i--){
            for(int j=0;j<v[s[k]-'0'].size();j++){
                if(v[s[k]-'0'][j] == (m[i]-'0')){
                    ss[i] = v[s[k]-'0'][j] + '0';
                    cnt++;
                    break;
                }
            }

            sss[i] = v[s[k]-'0'][v[s[k]-'0'].size()-1] + '0';
                
        }
        sss = sss.substr(lm-ls);
        ss = ss.substr(lm-ls);
    
        LL num = 0,num2 = 0,mm=0;
        if(cnt == ls)
        if(lm-ls-1 >= 0){
            m[lm-ls-1] = m[lm-ls-1];
            ss =  m.substr(0,lm-ls) + ss ;
            for(int i=0;i<ss.length();i++)
                num = num*10 + (ss[i]-'0');
        }
        
        for(int i=0;i<m.length();i++)
            mm = mm*10 + (m[i] - '0');

            m[lm-ls-1] = m[lm-ls-1] - 1;
            sss =  m.substr(0,lm-ls) + sss ;
        for(int i=0;i<sss.length();i++)
            num2 = num2*10 + (sss[i] - '0');
        cout<<min(mm,max(num,num2))<<endl;

    }
    return 0; 
}

