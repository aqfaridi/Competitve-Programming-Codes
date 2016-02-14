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
int maxArea(int hist[],int n)
{
    stack<LL> s;
    int maxx = 0,topArea;
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
int M[1010][1010];
int main()
{
    int n,t,m;
    char ch;
    int ans,result;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //scanf("%c",&ch);
                cin>>ch;
                if(ch=='F')
                    M[i][j] = 1;
                else
                    M[i][j] = 0;
            }
        }
        for(int i=1;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(M[i][j])
                    M[i][j] += M[i-1][j]; //cumm from above row
            }        

        result = 0;
        for(int i=0;i<m;i++)//rows
        {
            ans = maxArea(M[i],n);
            if(ans > result)
                result = ans;
        }
        printf("%lld\n",1LL*result*3);
    }
    return 0;
}


