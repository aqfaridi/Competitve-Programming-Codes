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
int cnt[26];
bool ispalin(string str,int l)
{
    for(int i=0;i<l/2;i++)
        if(str[i] != str[l-i-1])
            return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,l;
    string str;
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        cin>>str;
        l = str.length();

        if(ispalin(str,l)){
            cout<<1<<endl;
            continue;
        }
        for(int i=0;i<l;i++){
            if(str[i] == 'a')
                cnt[str[i]-'a']++;
            else
                cnt[str[i]-'a']++;
        }

        if(cnt[0] > 0 && cnt[1] > 0)
            cout<<2<<endl;
        else
            cout<<1<<endl;
    }
    return 0; 
}
