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
int lis[100],arr[100];
int main()
{
    int t,n;
    //cin>>t;
    t = 1;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            lis[i] = 1;
        }

        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                    lis[i] = lis[j] + 1;            
            }

        int maxx = lis[0];
        for(int i=1;i<n;i++)
            if(lis[i]>maxx)
                maxx = lis[i];
        cout<<maxx<<endl;
    }
    return 0;
}


