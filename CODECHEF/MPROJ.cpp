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
    int t,n,g,Acut,minsize,minripe,cnt,size,ripe;
    cin>>t;
    while(t--)
    {
        cnt = 0;
        cin>>n>>minsize>>minripe;
        for(int i=0;i<n;i++)
        {
            cin>>size>>ripe;
            if(size > minsize || ripe > minripe)
                cnt++;
        }
        cin>>Acut;
        g = __gcd(cnt,Acut);
        cout<<cnt/g<<"/"<<Acut/g<<endl;
    }
    return 0;
}
