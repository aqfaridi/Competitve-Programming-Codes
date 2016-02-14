#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int arr[100010];
int tle[100010];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,diff,ans;
    LL sum1=0;
    LL sum2 = 0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum1 += arr[i];
    }
    if(n==1)
    {
        cout<<-1<<endl;
        return 0;
    }


    sort(arr,arr+n);
    sum2 = n*(arr[0]+arr[n-1])/2;

    map<int,int> m;
    for(int i=1;i<n;i++)
        m[arr[i] - arr[i-1]]++;

    map<int,int>::iterator it;
    int size = m.size();
    if(m[0] > 0 || size>=3)
    {
        cout<<0<<endl;
        return 0;
    }
    

    if(n==2 && sum1==sum2)
    {
        diff = arr[1]-arr[0];
        if(diff&1)
        {
            cout<<2<<endl;
            cout<<arr[0]-diff<<" "<<arr[1]+diff<<endl;
        }
        else
        {
            cout<<3<<endl;
            cout<<arr[0]-diff<<" "<<arr[0]+diff/2<<" "<<arr[1]+diff<<endl;
        } 
        return 0;
    }
    
    if(sum1==sum2)
    {
        cout<<2<<endl;
        diff = arr[1]-arr[0];
        cout<<arr[0]-diff<<" "<<arr[n-1]+diff<<endl;
        return 0;
    }
    it = m.begin();
    int s1 = it->second,f1 = it->first;

    it++;
    int s2 = it->second,f2=it->first;

    
    if(s2>s1)
    {
        diff = f2;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]+diff==arr[i+1])
                continue;
            else
            {
                ans = arr[i]+diff;
                break;
            }
        }
        cout<<1<<endl;
        cout<<ans<<endl;
    }
    else
    {
        
        diff = f1;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]+diff==arr[i+1])
                continue;
            else
            {
                ans = arr[i]+diff;
                break;
            }
        }
        cout<<1<<endl;
        cout<<ans<<endl;
    }
        
    
    return 0;
}
