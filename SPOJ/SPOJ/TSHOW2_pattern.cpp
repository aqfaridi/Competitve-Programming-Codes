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

#define MAX 61
#define MOD 1000000007    
LL fib[MAX];
void make_fibo()
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=59;i++)
        fib[i] = fib[i-1] + fib[i-2];
}
int main()
{
    make_fibo();
    ios::sync_with_stdio(false);
    int t;
    LL n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n -= 1;
        cout<<fib[n%60]%10<<endl;
    }
    return 0;
}
