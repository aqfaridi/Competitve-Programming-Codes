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
int main()
{
    ios::sync_with_stdio(false);
    int t,n,l,cnt;
    int c,h,e,f;
    string str;
    t=1;
    while(t--)
    {
        cnt = c = h = e = f = 0;
        cin>>str;
        l = str.length();
        for(int i=0;i<l;i++)
        {
            if(str[i]=='C')
                c++;
            else if(c>=1 && h<c && str[i]=='H')
                h++;
            else if(h>=1 && e<h && str[i]=='E')
                e++;
            else if(e>=1 && f<e && str[i]=='F')
                f++;            
            if(c>=1 && h>=1 && e>=1 && f>=1)
            {
                cnt++;
                c-=1;h-=1;e-=1;f-=1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
