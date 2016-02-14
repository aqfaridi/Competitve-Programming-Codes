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
    int t;
    LL n,N;
    t = 1;
    while(t--)
    {
        cin>>n;
        if(n==0)
        {
            cout<<1<<endl;
            return 0;
        }
        N = n;
        n-=3;
        if(N==1 || N==2 || N==3)
        {
            cout<<(1<<(N+1))<<endl;
            return 0;
        }
        LL i,k=1,finalj;
        LL ans=0;
            for(int j=N-1;j>=1 && k<N;j--)
            {
               while(k<N)
               {
                if(N*N < (j*j + k*k))
                {
                    if(k-1-ans > 0)
                        ans += (k-1-ans);
                    finalj = j;
                    k++;
                    break;
                }
                k++;
                //cout<<k<<endl;
               }                
            }
      
           
        ans += finalj;
        cout<<4*(ans) <<endl;

    }
    return 0;
}
