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
#include<stack>
stack <pair<char,int> > st ;
vector <pair<int,int> > v;
int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i] == '(' or s[i] == '[')
            st.push(mp(s[i],i));
        else{
            if(s[i] == ']' and (!st.empty()) and st.top().first == '['){
                v.pb(mp(st.top().second , i));
                st.pop();
            }
            else if(s[i] == ')' and (!st.empty()) and st.top().first == '('){
                v.pb(mp(st.top().second , i));
                st.pop();
            }
            else{
                while(!st.empty())
                    st.pop();
            }
        }
    }
    sort(v.begin() , v.end());
    int siz = v.sz;
    int cnt = 0;
    int posl = -1;
    int posr = -1;
    int maxx = -1;
    for(int i=0;i<siz ;i++){
        pii p = v[i];
        if(posl < p.first and posr > p.second)continue;
        cnt = 0;
        cout<<p.first << "   " << p.second <<  endl;
        for(int j=p.first ; j<= p.second ; j++){
            if(s[j] == '[')
                cnt++;
        }
        if(cnt > maxx){
            posl = p.first;
            posr = p.second;
            maxx = cnt;
        }
    }
    if(maxx = -1)cout<<0<<endl;
    else{
        cout<<maxx<<endl;
        for(int i=posl ; i<= posr;i++)cout<<s[i];
        cout<<endl;
    }
    return 0;
}
