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
int cumm[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,l,r,w,k,tot,nahi,hai,len,num,z;
    string str;
    t=1;
    while(t--)
    {
        cin>>n>>k>>w;
        cin>>str;
        len = str.length();
        cumm[0] = 0;
        for(int i=0;i<len;i++)
        {
           if(str[i]=='1')
               cumm[i+1] = cumm[i] + 1;
           else
               cumm[i+1] = cumm[i];
        }
        for(int i=0;i<w;i++)
        {
            nahi = hai = 0;
            cin>>l>>r;
            tot = cumm[r] - cumm[l-1];
            num = l+k-1;
            if(k==1)
            {
                cout<<r-l+1 - tot<<endl;
                continue;
            }
            z = 1;
            while(num <= r)
            {
                if(str[num-1]!='1')
                    nahi++;
                else
                    hai++;
                z++; 
                num = (l + z*k -1);
            }
            cout<<(tot - hai)+nahi<<endl;
        }
    }
    return 0;
}
