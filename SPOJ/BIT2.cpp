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
LL bitsum(LL n)
{
    LL total = 0;
    for(int i = __lg(n);n>0;i=__lg(n))
    {
        total += (i*(1LL<<(i-1)) + (n-(1LL<<i)+1));
        n ^= (1LL<<i);//reset ith bit
    }
    return total;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n,low,high,mid,bits;
    cin>>t;
    while(t--)
    {
        cin>>n;
        low = 0;high = n;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            bits = bitsum(mid);
            if(bits == n)
            {
                cout<<mid<<endl;
                goto down;
            }
            if(bits > n)
                high = mid-1;
            else
                low = mid +1;
        }
        cout<<"Does Not Exist."<<endl;  
down:;
    }
    return 0;
}
