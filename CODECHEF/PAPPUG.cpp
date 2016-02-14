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
int cnt = 0;
namespace KMP
{
    #define MAX 10010
    int b[MAX],m,n;
    void LPS(string pat)
    {
        int i=0,j=-1;//j => border
        m = pat.length();
        b[i] = j;
        while(i<m)
        {
            while(j>=0 && pat[i]!=pat[j]) j=b[j];//next widest border
            i++;j++;
            b[i] = j;
        }
    }
    void kmpSearch(string txt,string pat)
    {    
        int i=0,j=0;
        n = txt.length();
        while(i<n)
        {
            while(j>=0 && txt[i]!=pat[j]) j=b[j];//next widest border of some prefix of pat
            i++;j++;
            if(j==m)
            {
                //printf("%d\n",(i-j));
                cnt++;
                j = b[j]; //widest border of pat
            }
    
        }

    }
}
using namespace KMP;
int main()
{
    ios::sync_with_stdio(false);
    int t,n,q;
    string str,pat;
    cin>>t;
    while(t--)
    {
        cin>>str;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            cin>>pat;
            cnt = 0;
            LPS(pat);
            kmpSearch(str,pat);
            cout<<cnt<<endl;
        }
    }
    return 0;
}
