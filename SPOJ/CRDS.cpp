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
    long long t,n,res;
    cin>>t;
    while(t--)
    {
        cin>>n;
        res = (3*n*n + n) / 2; 
        cout << res % 1000007 << endl;    
    }
    return 0;
}


