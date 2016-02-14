
/*******************************
// Author : Abdul Qadir Faridi
// IPG-3rd yr
// Institute : ABV-IIITM,Gwalior
*********************************/

//header files

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>

using namespace std;

//typedef

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<int,pii> tri;

#define MAX 1000010
#define MOD 1000000007
LL gcd(LL a,LL b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

LL lcm(LL a,LL b)
{
    return (a*b)/gcd(a,b);
}
struct node
{
    double d; 
    int C,M;
};
node plan[100001];
double v[100001];
int main()
{
    int t;
    LL U,N,mm,cc;
    LL LCM;
    double D,dd;
    cin>>t;
    while(t--)
    {
        cin>>D>>U>>N;
        LCM = 1;
        for(int i=1 ; i<= N; i++)
        {
            cin>>mm>>dd>>cc;
            plan[i].d = dd;
            plan[i].C = cc;
            plan[i].M = mm;
            LCM = lcm(mm,LCM);
        }
       
        for(int i=1;i<=N;i++)
        {
            LL num = (LCM / plan[i].M);
            v[i] = num * (1.0 * plan[i].M * plan[i].d * U + plan[i].C);
        }
/******************************************************** 
        for(int i=1;i<=N;i++)
        {
            cout<<v[i]<<endl;
        }
********************************************************/ 
        double minn = 1e300;
        int pos;
        cout<<minn<<endl;
        for(int i=1;i<=N;i++)
        {
            if(v[i] < minn)
            {
                minn = v[i];
                pos = i;
            }
        }
        double initial = 1.0 * D * U * LCM;
        
        if( initial - v[pos] >= 0.0000005 )
            cout<<pos<<endl;
        else
            cout<<0<<endl;
    }
    return  0;
}
