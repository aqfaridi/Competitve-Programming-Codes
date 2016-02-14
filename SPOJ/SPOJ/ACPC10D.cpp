#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int main()
{
    int n,cases=0;
    while(1)
    {
        scanf("%d",&n);
        cases++;
        if(n==0)
            break;
        int arr[n][5];
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            arr[i][0] = INT_MAX;
            arr[i][4] = INT_MAX;
        }
        arr[0][3] += arr[0][2];//0th row
        //cout<<arr[0][1]<<" "<<arr[0][2]<<" "<<arr[0][3]<<endl;
        //1st row
       
       
            arr[1][1] += arr[0][2];
            arr[1][2] += min(arr[0][2],min(arr[1][1],arr[0][3]));
            arr[1][3] += min(arr[0][2],min(arr[0][3],arr[1][2]));
        
        //cout<<arr[1][1]<<" "<<arr[1][2]<<" "<<arr[1][3]<<endl;
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                arr[i][j] += min(arr[i-1][j-1],min(arr[i-1][j+1],min(arr[i-1][j],arr[i][j-1])));
                //cout<<arr[i][j]<<" ";
            }
            //cout<<endl;
        }
        printf("%d. %d\n",cases,arr[n-1][2]);
      
    }
    return 0;
}

