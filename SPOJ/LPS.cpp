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

#define MAX 100010
#define MOD 1000000007    

namespace manacher
{
    int P[MAX],n,cnt;
    string sub;
    char s[MAX];
    //append ^$ to avoid bound check
    string make_T()
    {
        int n = strlen(s);
        if(n==0)    return "^$";
        string ret = "^";
        for(int i=0;i<n;i++)
        {
            sub = s[i];
            ret += ("#" + sub);
        }
    
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

    int LPSub()
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
        return maxlen;
    }

    int count_all()
    {
        cnt = 0;
        for(int i=1;i<n-1;i++)
            cnt += (P[i]+1)/2;
        return cnt;
    }

    int process_all()
    {
        int sum=0;
        for(int i=1;i<n-1;i+=2)
            sum += P[i];
        return sum;
    }


}
using namespace manacher;
int main()
{
    int t,l;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%s",s);
       make_T();
       make_P();
       printf("%d\n",LPSub());
    }
    return 0;
}
