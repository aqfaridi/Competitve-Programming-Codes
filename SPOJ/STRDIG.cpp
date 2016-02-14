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
    int t,n;
    string str,sub;
    for(int i=1;i<=1000000;i++)
    {
        ostringstream convert;
        convert << i;
        str += convert.str();
    }
    cout<<str<<endl;
    cin>>t;
    while(t--)
    {
        cin>>n;
        
    }
    return 0;
}


