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

#define MAX 50029
#define MOD 1000000007
LL arr[MAX],cumm[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    LL total,sum,cnt,maxx,posi;
    cin>>t;
    while(t--)
    {
        cin>>n;
        posi = 0;
        maxx = -1;
        sum = total = cnt = 0;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cumm[0] = 0;

        for(int i=0;i<n;i++)
            cumm[i+1] = cumm[i] + arr[i];

        posi = max_element(arr,arr+n) - arr;
        maxx = arr[posi];
        
        int idx = 0;
        while(posi<n)
        {
            sum = cumm[posi] - cumm[idx]; 
            total += maxx*(posi-idx) - sum;            
            idx = posi+1;
            posi = max_element(arr+posi+1,arr+n) - arr;
            maxx = arr[posi]; 
        }
        cout<<total<<endl;

    }
    return 0;
}
