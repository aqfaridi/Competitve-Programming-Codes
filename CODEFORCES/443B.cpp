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

namespace suffixArray
{
            
    #define MAX 510
    #define rep(i,n) for(int i=0;i<n;i++)
    int n,gap;
    int sa[MAX],pos[MAX],tmp[MAX],lcp[MAX];
    string nstr;
    bool cmp(int i,int j)
    {
        if(pos[i] != pos[j])
            return pos[i]<pos[j];
        i+=gap;j+=gap;
        return (i<n && j<n) ? pos[i]<pos[j] : i>j;//if ith pos reached end then return 1(i>j) since ith is smaller
    }
    void buildSA()
    {
        n = nstr.length();
        rep(i,n)    sa[i] = i , pos[i] = nstr[i];//ascii value in pos firsttime
        for(gap = 1;;gap*=2)
        {
            sort(sa,sa+n,cmp);
            rep(i,n-1)  
                tmp[i+1] = tmp[i] + cmp(sa[i],sa[i+1]);//lexo. names acc.to pos(prev)::increment by 1 when diff occurs
            rep(i,n)
                pos[sa[i]] = tmp[i];//pos updated by rank
        
            //terminating condition
            if(tmp[n-1] == n-1) break;//all rank assigned no further changes in tmp
        }
    }
    void buildLCP()
    {
        for(int i=0,k=0 ; i<n ; i++)
        {
            if(pos[i] != n-1)//no adjacent suffix exists
            {
                for(int j = sa[ (pos[i]+1) ] ; nstr[i+k] == nstr[j+k];)
                {
                    ++k;
                }
                lcp[pos[i]] = k;
                if(k)//next lcp(suffix and its adj.) is atleast k-1 
                    --k;
            }        
        }
    }

} 
using namespace suffixArray;
int main()
{
    ios::sync_with_stdio(false);
    int k,l,ans = -(1<<20),start_idx,end_idx;
    string str,sub;
    cin>>str;
    cin>>k;
    l = str.length();
    if(k >= l)
    {
        ans = l + (k/l)*l;
        cout<<ans<<endl;
        return 0;
    }

    for(int i=0;i<=l-k;i++)
    {        
        sub = str.substr(i,k);
        nstr = str+sub;
        buildSA();
        buildLCP();
        for(int i=0;i<l+k-1;i++)
        {
            for(int j=i+1;j<l+k;j++)
            {        
                end_idx = sa[j]+lcp[i]-1;
                start_idx = sa[i];
                //trace3(j,sa[j],lcp[i]);
                //trace3(i,start_idx,end_idx);
                if(start_idx == end_idx+1) //valid
                    ans = max(ans,lcp[i]*2);
            
                //trace2(lcp[j],lcp[i]);
                if(lcp[i] == 0 || lcp[j] < lcp[i])
                    break;
            }
        }
    }
    cout<<ans<<endl;
    return 0; 
}
