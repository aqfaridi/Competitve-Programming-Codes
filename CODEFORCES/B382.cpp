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
int a,b,w,x,c;
bool binary(int mid)
{
    if(b>=x) 
        b = b-mid*x;
    else
    {
        b = mid*w - mid*x + b;
        a = a-mid;
    }
    c = c - mid;

    if(c<=a)
        return true;
    else
        return false;

}
int main()
{
    cin>>a>>b>>w>>x>>c;
    int mid,low=0,high=w;
    while(low<high)
    {
        mid = (low+high)/2;
        if(binary(mid))
            high = mid - 1;
        else 
            low = mid + 1;
    }
    cout<<low<<endl;
        
    
    return 0;
}
