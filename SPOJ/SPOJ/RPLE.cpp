#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int t,a,b,n,r,cases = 0;
    bool check;
    set<int> r1,r2;
    scanf("%d",&t);
    while(t--)
    {
        check = true;
        cases++;
        r1.clear();
        r2.clear();
        scanf("%d %d",&n,&r);
        for(int i=0;i<r;i++)
        {
            scanf("%d %d",&a,&b);
            r1.insert(a);
            r2.insert(b);
        }
        //already sorted in set
        for(int i=0;i<n;i++)//upto n
        {
            if(r1.count(i)>0 && r2.count(i)>0) //same spy present in both
            {
                //cout<<i<<endl;
                check = false;
                break;
            }
        }
        if(check)
            printf("Scenario #%d: spying\n",cases);
        else
            printf("Scenario #%d: spied\n",cases);
    }

    return 0;
}

