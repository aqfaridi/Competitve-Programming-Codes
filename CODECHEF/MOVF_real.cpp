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
#define DEBUG if(0)
LL arr[1100];
int main()
{
    LL t,n,kk,cnt;
    string str;
    char ch;
    cin>>t;
    ch = getchar();
    while(t--)
    {
        cnt = 0;
        cin>>n>>kk;
        ch = getchar();
        for(int i=0;i<n;i++)
        {
            getline(cin,str);
            cin>>arr[i];
            ch = getchar();
        }
        sort(arr,arr+n);

        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                {
                    if(arr[i]+arr[j]+arr[k] == kk)
                        cnt++;
                }
        
        cout<<cnt<<endl;
        
    }
    return 0;
}
