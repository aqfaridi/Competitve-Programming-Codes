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
#include <climits>
#define MAX 100010
#define MOD 1000000007
int cnt[26];
string s[] = {"ALICE WINS","BOB WINS"};
int main()
{
    ios::sync_with_stdio(false);
    int t,n,l,num,num1,num2,idx;
    string str;
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        n-=1;
        cin>>str;
        l = str.length();
        for(int i=0;i<l;i++)
           cnt[str[i]-'a']++;
        num1 = *max_element(cnt,cnt+26);
        num2 = INT_MAX;
        for(int i=0;i<26;i++)
            if(cnt[i] > 0 && cnt[i] < num2)
                num2 = cnt[i];
        //trace2(num1,num2);
        num = num1 - num2;
        if((num&1))
            cout<<s[1-n]<<endl;
        else if(num == 0)
            cout<<"DRAW"<<endl;
        else
            cout<<s[n]<<endl;
    }
    return 0; 
}
