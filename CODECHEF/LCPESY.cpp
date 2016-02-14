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
string str1,str2;
int arr1[256],arr2[256];
int solve()
{
    int cnt = 0;
    memset(arr1,0,sizeof(arr1));
    memset(arr2,0,sizeof(arr2));
    int l1=str1.length(),l2=str2.length();
    for(int i=0;i<l1;i++)
        arr1[(int)str1[i]]++;
    
    for(int i=0;i<l2;i++)
        arr2[(int)str2[i]]++;

    for(int i=0;i<256;i++)
        cnt += min(arr1[i],arr2[i]);
    
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        cout<<solve()<<endl;
    }
    return 0;
}
