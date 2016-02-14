#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MOD 1000000007   

namespace manacher
{
    #define MAX 100010
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

    void LPSub()
    {
        int maxlen = 0;
        int center = 0;
        int cnt = 0;
        for(int i=1;i<n-1;i++)
        {
            if(P[i] > maxlen)
            {
                maxlen = P[i];
                center = i;
            }
        }
        for(int i=1;i<n-1;i++)
            if(P[i] == maxlen)
                cnt++;
        cout<<maxlen<<" "<<cnt<<endl;
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
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>s;
        make_T();
        make_P();
        LPSub();
    }
    return 0;
}
