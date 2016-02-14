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
int arr[30];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,nn;
    string s;
    cin>>s;
    n = s.length();
    for(int i=0;i<n;i++)
        arr[s[i]-'a']++;          
    if(arr[13]>=3)
        nn = 1 + (arr[13]-3)/2;
    else
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<min(nn,min(arr[8],min(arr[19],arr[4]/3)))<<endl;
    return 0;
}
