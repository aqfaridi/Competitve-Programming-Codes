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
int mark[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool f;
    int n,p,pr,l,r,rl,rr,d;
    string str,temp;
    cin>>n>>p;
    cin>>str;
    str = "$" + str;
    temp = str;

    l = n+1;
    r = 0;
    if(p <= n/2){
        for(int i=1;i<=n;i++)
            if(str[i] != str[n-i+1]){
                r = max(r,i);
                l = min(l,i);
                mark[i] = 1;
            }
    }else{
        for(int i=1;i<=n;i++)
            if(str[i] != str[n-i+1]){
                r = max(r,n-i+1); 
                l = min(l,n-i+1);
                mark[n-i+1] = 1;
            }
    }

    for(int i=1;i<=n;i++)    mark[i] += mark[i-1];
    int t=0,prev=0,diff,cost;
    int ans = 0;
        for(int i=p;i<=n;i++,t++)
            if(str[i] != str[n-i+1]){
                diff = abs(str[i] - str[n-i+1]);
                cost = min(diff,abs(26-diff));
                ans += (cost + (t-prev));
                str[n-i+1] = str[i] = '$';
                prev = t;
            }

        for(int i=1;i<p;i++,t++)
            if(str[i] != str[n-i+1]){
                diff = abs(str[i] - str[n-i+1]);
                cost = min(diff,abs(26-diff));
                ans += (cost + (t-prev));
                str[n-i+1] = str[i] = '$';
                prev = t;
            }
        
    /**************************************/

        t=0;prev=0;
        int ans2=0;
        str = temp;
    
        for(int i=p;i>=1;i--,t++)
            if(str[i] != str[n-i+1]){
                diff = abs(str[i] - str[n-i+1]);
                cost = min(diff,abs(26-diff));
                ans2 += (cost + (t-prev));
                str[n-i+1] = str[i] = '$';
                prev = t;
            }    

        for(int i=n;i>p;i--,t++)
            if(str[i] != str[n-i+1]){
                diff = abs(str[i] - str[n-i+1]);
                cost = min(diff,abs(26-diff));
                ans2 += (cost + (t-prev));
                str[n-i+1] = str[i] = '$';
                prev = t;
            }
   
    /*************************************/


        t=0;prev=0;
        str = temp;
        int ans3 = 0;
   
        for(int i=p;i>=1;i--,t++)
            if(str[i] != str[n-i+1]){
                diff = abs(str[i] - str[n-i+1]);
                cost = min(diff,abs(26-diff));
                //trace2(cost,(t-prev));
                ans3 += (cost + (t-prev));
                str[n-i+1] = str[i] = '$';
                prev = t;
            }
        
        pr = prev;
        //ans3 += prev;
        t = 1; prev = 0;
        f = false;
        for(int i=p+1;i<=n;i++,t++)
            if(str[i] != str[n-i+1]){
                diff = abs(str[i] - str[n-i+1]);
                cost = min(diff,abs(26-diff));
                //trace2(cost,(t-prev));
                ans3 += (cost + (t-prev));
                str[n-i+1] = str[i] = '$';
                prev = t;
                f = true;
            }
        if(f);
        ans3 += pr;
  
        /*****************************************/
        t=0;prev=0;
        str = temp;
        int ans4 = 0;
   
        for(int i=p;i<=n;i++,t++)
            if(str[i] != str[n-i+1]){
                diff = abs(str[i] - str[n-i+1]);
                cost = min(diff,abs(26-diff));
                ans4 += (cost + (t-prev));
                str[n-i+1] = str[i] = '$';
                prev = t;
            }

        //ans4 += prev;
        //cout<<ans4<<endl;
        pr = prev;

        t = 1; prev = 0;
        f = false;
        for(int i=p-1;i>=1;i--,t++)
            if(str[i] != str[n-i+1]){
                diff = abs(str[i] - str[n-i+1]);
                cost = min(diff,abs(26-diff));
                ans4 += (cost + (t-prev));
                str[n-i+1] = str[i] = '$';
                prev = t;
                f = true;
            }
        if(f)
            ans4 += pr;

    //cout<<ans<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
    ans = min(ans,min(min(ans2,ans3),ans4));
    cout<<ans<<endl;

        /*
    for(int i=1;i<=n;i++)    mark[i] += mark[i-1];

    if(mark[p-1] && mark[p+1]){
        rl = abs(p-l+1);
        rr = abs(r-p+1);
        if(rl <= rr)
            d = -1;
        else
            d = 1;
    }
    else if(mark[p-1])
        d = -1;
    else if(mark[p+1]){
        d = 1;
        while(mark[p+d]){
            
        }
    else{ 
        d = 0;
        cout<<0<<endl;
    }
    */
    return 0; 
}

