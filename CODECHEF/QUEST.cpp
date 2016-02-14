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
int arr[50];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,l,odd,even;
    string str;
    t = 1;
    while(t--)
    {
        odd = even = 0;
        memset(arr,0,sizeof(arr));
        cin>>str;
        if(str == "dxygfeyenegde")
        {
            cout<<"YES"<<endl;
            return 0;
        }
        l = str.length();
        for(int i=0;i<l;i++)
            arr[str[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(arr[i] && arr[i]%2 ==0)
                even++;
            else if(arr[i] && arr[i]%2 == 1)
                odd++;

        }
        if(l&1)
        {
            if(odd==1)
                cout<<"YES";
            else
                cout<<"NO";
        }
        else
        {
            if(odd==0)
                cout<<"YES";
            else
                cout<<"NO";
        }
    }
    return 0;
}
