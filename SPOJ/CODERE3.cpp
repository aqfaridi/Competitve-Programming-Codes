#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int arr[1010],lis[1010],lisb[1010];
int main()
{
    int t,n,maxx;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            lis[i] = lisb[i] = 1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((arr[i] > arr[j]) && (lis[i] < lis[j]+1))
                    lis[i] = lis[j] + 1;                    
            }
        }
        reverse(arr,arr+n);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((arr[i] > arr[j]) && (lisb[i] < lisb[j]+1))
                    lisb[i] = lisb[j] + 1;                    
            }
        }
       
        maxx = -INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxx = max(maxx,lis[i]+lisb[i]-1);
        }
        
        cout<<maxx<<endl;

    }
    return 0;
}


