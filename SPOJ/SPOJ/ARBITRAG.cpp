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
#define DEBUG if(0)
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
double Arb[50][50];
int main()
{
    int n,mm,u,v,cases=0;
    bool flag;
    string str,str1,str2;
    double cost;
    //scanf("%d",&t);
    while(1)
    {
        cases++;
        map<string,int> m;
        flag = false;
        scanf("%d",&n);
        memset(Arb,0.0,sizeof Arb);
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
        {
            cin>>str;
            m[str] = i;
        }
        scanf("%d",&mm);
        for(int i=0;i<mm;i++)
        {
            cin>>str1>>cost>>str2;
            u = m[str1];
            v = m[str2];
            Arb[u][v] = cost;
        }
        DEBUG
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                cout<<Arb[i][j]<<" ";
            cout<<endl;
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    Arb[i][j] = max(Arb[i][j],Arb[i][k]*Arb[k][j]);  
        }
        DEBUG
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                cout<<Arb[i][j]<<" ";
            cout<<endl;
        }
        for(int i=1;i<=n;i++)
            if(Arb[i][i] > 1.0)
            {
                flag = true;
                break;
            }
        if(flag == true)
            cout<<"Case "<<cases<<": Yes"<<endl;
        else
            cout<<"Case"<<cases<<": No"<<endl;

    }
    return 0;
}

