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
    int t,n,k;
    LL total,cnt;
    bool flag;
    cin>>t;
    while(t--)
    {
        total = 0;
        cin>>n>>k;
        for(int i=0;i<(1LL<<n);i++)
        {
            flag = true;
            for(int j=0;j<32;j++)
            {
                cnt = 0;
                while(j<n && cnt<k && (i & (1<<j)))
                {
                    cnt++;
                    j++;
                }
                if(cnt == k)
                    j--;
                if(cnt > 0 && cnt != k)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                total++;
            }
            
        }
        cout<<total<<endl;
    }
    return 0;
}
