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

#define MOD 1000000007
namespace manacher
{
    #define MAX 5010
    int P[MAX],n,cnt;
    string s;
    //append ^$ to avoid bound check
    string make_T()
    {
        int n = s.length();
        if(n==0)    return "^$";
        string ret = "^";
        for(int i=0;i<n;i++)
            ret += ("#" + s.substr(i,1));

        ret += "#$";

        return ret;
    }

    void make_P()
    {
        string T = make_T();
        n = T.length();
        int C = 0 , R = 0;
        for(int i=1;i<n-1;i++)
        {
            int i_mirror = C - (i-C);
            P[i] = (R>i) ? min(R-i,P[i_mirror]) : 0;//if i is after R then initialize P[i] =0
            //expand palin centered at i
            while(T[i+1+P[i]] == T[i-1-P[i]])
                P[i]++;
            //if palin centered at i expand past R,
            //adjust new center and new Right Edge
            if(i+P[i] > R)
            {
                C = i;
                R = i + P[i];
            }
       }
    }

    string LPSub()
    {
        int maxlen = 0;
        int center = 0;
        for(int i=1;i<n-1;i++)
        {
            if(P[i] > maxlen)
            {
                maxlen = P[i];
                center = i;
            }
        }
        return s.substr((center-1-maxlen)/2,maxlen);
    }

    int count_all()
    {
        cnt = 0;
        for(int i=1;i<n-1;i++)
            cnt += (P[i]+1)/2;
        return cnt;
    }
    void print_all()
    {
        int center,l;
        for(int i=1;i<n-1;i++)
        {
            center = i;
            l = 2;
            if(P[i] & 1)
                l = 1;
            for(;l<=P[i];l+=2)
                cout<<s.substr((center-1-l)/2,l)<<endl;

        }
    }

    void process_all()
    {
        int center,l;
        for(int i=1;i<n-1;i++)
        {
            center = i;
            l = 2;
            if(P[i] & 1)
                l = 1;
            for(;l<=P[i];l+=2)
            {
                //process length of each palin = l

            }

        }
    }

}
using namespace manacher;

int main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    make_P();
    for(int i=0;i<n;i++)
        cout<<P[i]<<" ";
    cout<<endl;
    
    int q,a,b,cnt;
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        cnt = 0;
        for(int i=2*a;i<=2*b;i++)
            cnt += (P[i]+1)/2;
        cout<<cnt<<endl;
    }
    return 0;
}
