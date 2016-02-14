#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <stack>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MAX 100010
LL hist[MAX];
LL maxArea(int n)
{
    stack<LL> s;
    LL maxx = 0,topArea;
    int i=0,topidx;
    while(i<n) 
    {
        if(s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            topidx = s.top();
            s.pop();
            topArea = hist[topidx] * ((s.empty())?i:(i-s.top()-1));//not incl ith
            if(topArea > maxx)
                maxx = topArea;
        }
    }
    while(s.empty()==false)
    {
        
        topidx = s.top();
        s.pop();
        topArea = 1LL*hist[topidx] * ((s.empty())?i:(i-s.top()-1));//not incl ith
        if(topArea > maxx)
            maxx = topArea;
    }
    return maxx;
}
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(int i=0;i<n;i++)      
            scanf("%lld",&hist[i]);
        printf("%lld\n",maxArea(n));
    }
    return 0;
}


