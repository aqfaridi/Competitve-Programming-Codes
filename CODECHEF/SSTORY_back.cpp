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
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define debug                       if(1)
#define debugoff                    if(0)    

#define MAX 1000020
#define rep(i,n) for(int i=0;i<n;i++)
LL n,g;
LL s[MAX],p[MAX],t[MAX],lc[MAX];
char str[MAX];
bool cmp(int i,int j)
{
    if(p[i] != p[j])
        return p[i]<p[j];
    i+=g;j+=g;
    return (i<n && j<n) ? p[i]<p[j] : i>j;
}
void preProcess_s()
{
    n = strlen(str);
    rep(i,n)    s[i] = i , p[i] = str[i];
    for(g = 1;;g*=2)
    {
        sort(s,s+n,cmp);
        rep(i,n-1)  
            t[i+1] = t[i] + cmp(s[i],s[i+1]);
        rep(i,n)
            p[s[i]] = t[i];
        if(t[n-1] == n-1) break;
    }
}
LL maxx;
void preProcess_l()
{
    for(int i=0,k=0 ; i<n ; i++)
        if(p[i] != n-1)
        {
            for(int j = s[ (p[i]+1) ] ; str[i+k] == str[j+k];)
                ++k;
            lc[p[i]] = k;
            if(k) 
                --k;
        }        
}
int main()
{
    LL idx;
    char str1[MAX],str2[MAX];
    scanf("%s",str1);
    scanf("%s",str2);
    strcpy(str,str1);
    LL l = strlen(str1);
    str[l] = '$';
    strcat(str,str2);
    preProcess_s();
    preProcess_l();
    maxx = 0;
    for(int i=0;i<n;i++)
    {

        if(s[i]>l && s[i+1]<l)
        {
            if(lc[i] > maxx)
            {
                maxx = lc[i];
                idx = s[i];
            }
            else if((lc[i] == maxx) && s[i] < idx)
                 idx = s[i];
        }
       
        if(s[i]<l && s[i+1]>l)
        {
            if(lc[i] > maxx)
            {
                maxx = lc[i];
                idx = s[i+1];
            }
            else if((lc[i] == maxx) && s[i+1] < idx)
                 idx = s[i+1];
        }
    }
    if(maxx == 0)
    {
        cout<<0<<endl;
        return 0;
    }

    for(int i=idx;i<(idx+maxx);i++)
        cout<<str[i];
    cout<<endl;
    cout<<maxx<<endl;
    return 0;
}


