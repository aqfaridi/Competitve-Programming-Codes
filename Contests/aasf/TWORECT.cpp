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
int main()
{
    ios::sync_with_stdio(false);
    int t,x1,x2,y1,y2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1>y1)
            swap(x1,y1);
        if(x2>y2)
            swap(x2,y2);
        if(x1>=x2 && y1>=y2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
