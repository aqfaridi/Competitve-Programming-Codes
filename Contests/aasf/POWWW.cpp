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
    int t,n,two,three,var;
    cin>>t;
    while(t--)
    {
        cin>>n;
        two = three = 0;
        for(int i=0;i<n;i++)
        {
            cin>>var;
            while(var%2 == 0)
            {
                two++;
                var /= 2;
            }
            while(var%3 == 0)
            {
                three++;
                var /= 3;
            }
        }
        if(n-two < 0)
            cout<<0<<" ";
        else
            cout<<n-two<<" ";

        if(n-three < 0)
            cout<<0<<" ";
        else
            cout<<n-three<<endl;
    }
    return 0;
}
