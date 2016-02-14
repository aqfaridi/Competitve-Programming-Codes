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
int arr[100010];
int main()
{
    int n,k;
    cin>>n>>k;
    if(n==k)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=n;i>=(n-k+1);i--)
        arr[i] = i;
    for(int i=n-k;i>=2;i--)
        arr[i] = i-1;
    arr[1] = n-k;
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
