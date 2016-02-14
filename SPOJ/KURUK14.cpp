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

#define MAX 1010
#define MOD 1000000007    
vector<int> v;
int arr[MAX];
bool compute(int n,bool even)
{
    int val1,val2;
    bool f = false;
    int loop = n/2 - 1;
    if(!even)
    {
        if(arr[n/2]!=1)
            return false;
    }
    f = true;
    for(int i=2;i<loop+2;i++)
    {
        val1 = n-i;
        val2 = (n-1 - val1);
        if(arr[val1]==2 || arr[val2]==2 || (arr[val1]==1 && arr[val2]==1))              continue;
        else 
        {
            f = false;
            break;
        }
    }
    return f;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n,var;
    bool ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++)
        {
            cin>>var;
            arr[var]++;
        }
        if(arr[n-1]!=2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(n&1)
            ans = compute(n,0);
        else
            ans = compute(n,1);

        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}
