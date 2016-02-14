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

#define MAX 10010
#define MOD 1000000007    
int check[MAX],arr[MAX],psum[MAX],cumm[MAX],minn,cnt;
void prefix_sum(int n)
{
    cumm[0] = 0;
    psum[n-1] = 0;
    cnt = 0;
    if(arr[0] == minn)
        cnt = 1;

    for(int i=1;i<n;i++)
    {
        if(arr[i-1] == minn)
            cumm[i] = cumm[i-1] + 1;
        else
            cumm[i] = cumm[i-1];

        if(arr[n-i] == minn)
            psum[n-1-i] = psum[n-i] + 1;
        else
            psum[n-1-i] = psum[n-i];
        
        if(arr[i] == minn)
            cnt++;
    }
}
int kitne,flag,zeros;
void reset()
{
    kitne = zeros = 0;
    memset(check,0,sizeof(check));
    memset(psum,0,sizeof(psum));
    memset(cumm,0,sizeof(cumm));
    flag = false;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        reset();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i] == 0)
                zeros++;

            if(arr[i] >= n)
                flag = true; 
            else
                check[arr[i]] = 1;
        }

        for(int i=0;i<n;i++)
            if(check[i])    kitne++;

        minn = *min_element(arr,arr+n);
        if(flag || kitne >= 3)
        {
            cout<<-1<<endl;
            continue;
        }
        if(zeros == n)
        {
            cout<<0<<endl;
            continue;
        }
        prefix_sum(n);

        for(int i=0;i<n;i++)
        {
            if(arr[i] != (psum[i] + cumm[i]))
            {
                flag = true;
                break;
            }
        }
       
        if(!flag)
            cout<<cnt<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
