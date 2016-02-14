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

#define MAX 10010
#define MOD 1000000007  
#define gc getchar_unlocked 
inline void readNat(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());//ignore whitespace in front
    //2x + 8x = 10x  optimisation
    for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}
int arr[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,pro,diff;
    LL sum;
    readNat(&t);
    while(t--)
    {
        sum = 0;
        readNat(&n);
        readNat(&arr[0]);
        for(int i=1;i<n;i++)
        {
            readNat(&arr[i]);
            diff = arr[i] - arr[i-1];
            pro = i*(n-i);
            sum += (pro*diff);
        }

        cout<<sum<<endl;
    }
    return 0;
}
