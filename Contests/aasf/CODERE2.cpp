#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
#include <algorithm>
#define mp                          make_pair
#define pb                          push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,maxx,number;
    int n,num,size,cnt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
    
        sort(arr,arr+n);
        maxx = 1;
        number = arr[0];
        for(int i=0;i<n-1;i++)
        {
            cnt = 1;
            if(arr[i]==arr[i+1])
            {
                while(i<n-1 && arr[i]==arr[i+1])
                {
                    cnt++;
                    i++;
                }
            }
            if(maxx < cnt)
            {
                maxx = cnt;
                number = arr[i];
            }
            else if(maxx == cnt)
            {
                if(number > arr[i])
                    number = arr[i];
            }
                
        }
        cout<<number<<endl;
        
        
    }
    return  0;
}

