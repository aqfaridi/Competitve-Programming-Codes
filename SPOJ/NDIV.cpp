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
int divisors(int a,int b,int n)
{
    int cnt,i,send=0;
    for(int num=a ; num<=b ; num++)
    {
        cnt=0;
       for(i=1;i<sqrt(num);i++)
       {
            if(num%i==0)
                cnt+=2;
       }
       if(i*i == num)
           cnt += 1;
       if(cnt == n)
           send++;
    }
    return send;
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b,n;
    cin>>a>>b>>n;
    cout<<divisors(a,b,n)<<endl;
    return 0;
}


