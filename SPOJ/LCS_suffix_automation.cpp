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
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
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

#define MAX 250020
#define MOD 1000000007
char s[MAX],t[MAX];
namespace suffix_automation
{
    struct state 
    {
        int len,link;
        map<char,int> next;
    }; 
    
    const int MAXLEN = 250020;
    state st[MAXLEN*2];
    int sz,last; 
    void sa_init() 
    {
        sz = last = 0;
        st[0].len = 0;
        st[0].link = -1;
        sz++;
     }

    void sa_extend(char c) 
    {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p;
        for(p = last; p != -1 && !st[p].next.count(c);p = st[p].link)
            st[p].next[c] = cur;
        if (p == -1)
            st[cur].link = 0;
        else 
        {
            int q = st[p].next[c];
            if(st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else
            {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                for(;p != -1 && st[p].next[c] == q ; p = st[p].link)
                    st[p].next[c] = clone;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    int lcs(char* s,char* t)
    {
        int l1 = strlen(s);
        int l2 = strlen(t);
        sa_init( );
        for(int i=0;i < l1;i++)
            sa_extend(s[i]);
                 
        int v = 0,l = 0,best = 0,bestpos = 0;
        for(int i=0;i < l2;i++) 
        {
            while(v && !st[v].next.count(t[i])) 
            {
                v = st[v].link;
                l = st[v].len;
            }

            if(st[v].next.count(t[i])) 
            {
                v = st[v].next[t[i]];
                ++l;
            }
            if(l > best)
                best = l,bestpos = i;
        }
        return best;
    }
} 
using namespace suffix_automation;
int main()
{
    printf("%d\n",lcs(gets(s),gets(t)));
    return 0;
}


