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
namespace sieve
{
    #define MAX 1000010
    #define LIM 1000
    #define PRM 78500
    typedef long long LL;
    unsigned flag[MAX >> 6];
    LL primes[PRM];
    #define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
    #define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
    void make_sieve()
    {
        unsigned i,j,k;
        isc(1);
        for(i=3;i<=LIM;i+=2)
        {
            if(!ifc(i))
                for(j=i*i,k=(i<<1);j<MAX;j+=k)
                    isc(j);
        }
    }
}
using namespace sieve;
int R[2][100020];
int main()
{
    make_sieve();
    //ios::sync_with_stdio(false);
    int t,N,len,cnt,i,j,k,rp;
    string s;
    cin>>t;
    while(t--)
    {
      cin >> s;
      N = s.length(); 
      s = "@" + s + "#"; // insert 'guards' to iterate easily over s
      for(j = 0; j <= 1; j++)
      {
        R[j][0] = rp = 0; i = 1;
        while(i <= N)
        {
          while(s[i - rp - 1] == s[i + j + rp]) rp++;
          R[j][i] = rp;
          k = 1;
          while((R[j][i - k] != rp - k) && (k < rp))
          {
            R[j][i + k] = min(R[j][i - k],rp - k);
            k++;
          }
          rp = max(rp - k,0);
          i += k;
        }
      }

      s = s.substr(1,N); // remove 'guards'

      cnt = 0;

      for(i = 1; i <= N; i++)
      {
        for(j = 0; j <= 1; j++)
          for(rp = R[j][i]; rp > 0; rp--)
          {
            len = 2 * rp + j;
            //for(k=1;k<i-rp;k++) cout<<" ";
            //cout<<s.substr(i-rp-1,2*rp+j)<<endl;
            if(len == 2)
                cnt++;
            else if((len&1) && !ifc(len))
                cnt++;
          }
      }
      cout << cnt << endl;
    }
      return 0;
} 
