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
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m,test,d,k,range,posi;
    test = 1;
    while(test--)
    {
        k=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>m;
        for(int x=0;x<m;x++)
        {
            cin>>t>>d;
            k = 0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]+d >= arr[i+1])
                {
                    k++;
                    range = i+1;
                }
                if(k==1)
                    posi = i;
            }
            cout<<"k="<<k<<" "<<posi<<endl; 
            if(range-posi == k)
            {
               if(arr[range]<=t && arr[range+1]>t)
                   cout<<posi<<endl;
               else
                   cout<<1<<endl;
            }
            else
                cout<<1<<endl;
        }
    }
    return 0;
}
