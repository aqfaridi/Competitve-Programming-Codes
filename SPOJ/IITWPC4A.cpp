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
    LL t,n,m,cnt,l,maxx,minn;
    LL total;
    string str;
    cin>>t;
    while(t--)
    {
        total = cnt = 0;
        cin>>str;
        l = str.length();
        cin>>m>>n;
        for(int i=0;i<l;i++)
        {
            if(str[i]=='a')
            {
                cnt = 0;
                while(i<l && str[i]=='a')
                {
                    cnt++;
                    i++;
                }
                total += cnt/m;
            }
        }
        if(n>=m)
        {
            minn = l;
            maxx = l + (n-m)*total;
        }
        else
        {
            minn = l - (m-n)*total;
            maxx = l;
        }
        cout<<minn<<" "<<maxx<<endl;

        
        
    }
    return 0;
}
