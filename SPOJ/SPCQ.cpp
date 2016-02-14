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

int main()
{
    ios::sync_with_stdio(false);
    /*
    int sum = 0;
    for(int i=1;i<=10000000;i++)
    {
        int num = i;
        sum = 0;
        while(num)
        {
            sum += num%10;
            num /= 10;
        }
        if(i%sum == 0)
            cout<<i<<" ";
    }
*/
    int t;
    LL n,num,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(LL i=n;;i++)
        {
            num = i;
            sum = 0;
            while(num)
            {
                sum += (num%10);
                num /= 10;
            }
            
            if(i%sum == 0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
