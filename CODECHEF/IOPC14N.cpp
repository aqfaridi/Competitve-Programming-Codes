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

#define MAX 1000010
#define MOD 1000000007    
int a[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,m;
    cin>>t;
    string s ;
    while(t--)
    {
        cin>>s;
        cin>>m;
        int l = s.length() ;
     
        a[0] = 0;
        if(s[0] == 'A')
                a[1]=1;
        else
                a[1]= 0;
        for(int i = 2 ; i <= l ; i++)
        {
            if(s[i-1] == 'A')
                    a[i] = a[i-1]+1 ;
            else
                    a[i] =a[i-1];
        }
        int mn=10100000;
        for(int i = 1 ; i <= l-m+1 ; i++)
            mn= min(mn,m-(a[i+m-1]-a[i-1]));
        
        cout<<mn<<endl;
        



    }
    return 0;
}
