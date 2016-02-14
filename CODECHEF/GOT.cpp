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
    int t,n,sq;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2 == 0)
            cout<<"Valar Morghulis"<<endl;
        else
            cout<<"Lannisters always pays their debts"<<endl;
    }
    return 0;
}
