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
    int l,cnt;
    string str;
    while(getline(cin,str))
    {
        l = str.length();
        for(int i=0;i<l;i++)
        {
            cnt=1;
            while((i+1<l) && str[i]==str[i+1])
                {cnt++;i++;}
            if(cnt>=4)
                cout<<cnt<<"!"<<str[i];
            else
                while(cnt--)
                    cout<<str[i];
        }       
        cout<<endl;
    }
    return 0;
}
