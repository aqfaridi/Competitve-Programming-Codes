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

#define MAX 510
#define MOD 1000000007    
int arr[MAX][MAX],P[MAX][MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m,cnt;
    t = 1;
    while(t--)
    {
        cin>>n>>m;
        cnt=0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>P[i][j];
               
            
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               cin>>arr[i][j];
               if(arr[i][j])
               {
                   cnt++;
               }
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(arr[i][j])
                    cout<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<" "<<P[i][j]-arr[i][j]<<endl;
    }
    return 0;
}
