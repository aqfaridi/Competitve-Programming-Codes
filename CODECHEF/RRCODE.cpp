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
    unsigned int t,n,k,ans,AND,OR,XOR,num;
    string str;
    cin>>t;
    while(t--)
    {       
        cin>>n>>k>>ans;
        XOR = ans;
        AND = ans;
        OR = ans;

        for(int i=0;i<n;i++)
        {
            cin>>num;
            XOR ^= num;
            AND &= num;
            OR |= num;
        }
        cin>>str;
        if(k==0)
        {
            cout<<ans<<endl;
            continue;
        }
        if(!(str.compare("XOR")))
        {
            if(k%2==0)
                cout<<ans<<endl;
            else
                cout<<XOR<<endl;
        }
        else if(!(str.compare("AND")))
        {
            cout<<AND<<endl;
        }
        else if(!(str.compare("OR")))
        {
            cout<<OR<<endl;
        }
    }
    return 0;
}


