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
    char str[10];
    scanf("%d",&t);
    while(t--)
    {
        vector<string> v;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            v.push_back(string(str));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
            printf("%s\n",v[i].c_str());

    }
    return 0;
}


