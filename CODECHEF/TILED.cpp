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
int fib[MAX];
void fibo()
{
    fib[1] = 1;
    fib[2] = 2;
    for(int i=3;i<MAX;i++)
        fib[i] = (fib[i-1]+fib[i-2])%MOD;
}
int main()
{
    fibo();
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<fib[n]<<endl;
    }
    return 0;
}
