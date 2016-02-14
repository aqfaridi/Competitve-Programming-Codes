#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200010
int arr[MAX],cnt;
bool cmp(const int& a,const int& b)
{
    bool res = (a<b);
    if(res == 1)
        cnt++;
    cerr << res << endl;
    return res;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cnt = 0;
        cin>>n;
        for(int i=0;i<n;i++)    cin>>arr[i];
        for(int i=0;i<n;i++)    cout<<arr[i]<<" ";
        cout<<endl;
        sort(arr,arr+n,cmp);

        for(int i=0;i<n;i++)    cout<<arr[i]<<" ";
        cout<<endl;
        cout<<cnt<<endl;
    }
    return 0;
}
