#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000010
using namespace std;
int arr[MAX];
void precomp()
{
    arr[1] = 1;
    int k = 2;
    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<=arr[i];j++)
        {
            if(k==MAX-1)
                break;
            arr[k++] = i+1;
        }
        if(k==MAX-1)
            break;
    }
}
int main()
{
    int t,n,cases = 0;
    ios::sync_with_stdio(false);
    precomp();
    //for(int i=0;i<MAX;i++)
    //    cout<<arr[MAX-2]<<" ";
    cout<<endl;
    cin>>t;
    while(t--)
    {
        cases++;
        cin>>n;
        cout<<"Case #"<<cases<<": "<<arr[n]<<endl;
    }
    return 0;
}

