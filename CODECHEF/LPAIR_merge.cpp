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

int arr[MAX],temp[MAX];
long long int invcnt;
//calculating invcnt while merging
void merge(int low1,int up1,int low2,int up2)
{
    int i=low1,j=low2,k=low1,mid=up1;

    while(i<=up1 && j<=up2)  // if anyone list exhausted
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {
            // A[j]>A[i] and i<j(since i is in left tree)
            invcnt += (mid-i+1);
            temp[k++] = arr[j++];
        }

    }
    while(i<=up1)
        temp[k++]=arr[i++];
    while(j<=up2)
        temp[k++]=arr[j++];

    //copying
    for(int x=low1;x<k;x++)
        arr[x] = temp[x];

}
void mergesort(int low,int up) // 0-7
{
    int mid;
    if(low<up)
    {
        mid = (low+up)/2;   // 3
        mergesort(low,mid);  //0-3  => 0-1 & 2-3
        mergesort(mid+1,up); //4-7  => 4-5 & 6-7
        merge(low,mid,mid+1,up);
    }
}
vector< pii > v;
int main()
{
    ios::sync_with_stdio(false);
    int n,a,b,size;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    size = v.size();
    for(int i=0;i<size;i++)
        arr[i] = v[i].second;
    
    mergesort(0,size-1);
    cout<<invcnt<<endl;
}
