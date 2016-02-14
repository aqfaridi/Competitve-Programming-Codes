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

int main()
{
    ios::sync_with_stdio(false);
    int t,n,l;
    string str,sub;
    cin>>t;
    while(t--)
    {
        cin>>str;
        sub.clear();
        for(int i=0;str[i];i++)
        {
            while((str[i+1]) && str[i]==str[i+1]) i++;
            sub += str[i];                
        }
        
        l = sub.length();
        int k;
        for(k=0;k<l/2;k++)
            if(sub[k] != sub[l-k-1]) break;
        
        if(k == l/2 )
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
