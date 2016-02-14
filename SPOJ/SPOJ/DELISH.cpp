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
#define MAX 10010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int arr[MAX];
struct node
{
    int Imax;
    int Jmax;
    int Itemp;
    long long int max_sum;
};
node MaxSumArray(int a,int b)
{
    node ans;bool flag = false;
    long long int cumm_sum=0;
    ans.Imax = 1;
    ans.Jmax = 1;
    ans.Itemp = 1;
    ans.max_sum = 0;
    for(int i=1;i<=b;i++)
        if(arr[i]>0)
        {
            flag = true;
            break;
        }
    if(flag)    
    { 
        for(int i=a;i<=b;i++)
    	{
    		cumm_sum += arr[i];
    		if(cumm_sum <= 0){ans.Itemp = i+1;cumm_sum = 0;}
    		else if(ans.max_sum < cumm_sum){ans.Imax = ans.Itemp;ans.Jmax = i;ans.max_sum = cumm_sum;}
    	}
    }
    else
    {
        //all negative number or zero
        int* location = max_element(arr+a,arr+b+1);//[a,b]
        ans.Imax = ans.Jmax = (location - arr);
        ans.max_sum = *location;
    }
	return ans;
}

node MinSumArray(int a,int b)
{
	node ans;bool flag = false;
    long long int cumm_sum=0;
    ans.Imax = 1;
    ans.Jmax = 1;
    ans.Itemp = 1;
    ans.max_sum = 0;

    for(int i=1;i<=b;i++)
        if(arr[i]<0)
        {
            flag = true;
            break;
        }
    if(flag)
    {
    	for(int i=a;i<=b;i++)
    	{	
    		cumm_sum += arr[i];
    		if(cumm_sum >= 0){ans.Itemp = i+1;cumm_sum=0;}
    		else if(ans.max_sum > cumm_sum){ans.Imax = ans.Itemp; ans.Jmax = i; ans.max_sum = cumm_sum;}
    	}
    }
    else
    {
        //all positive number or zero
        int* location = min_element(arr+a,arr+b+1);//[a,b]
        ans.Imax = ans.Jmax = (location - arr);
        ans.max_sum = *location;
    }
	return ans;
}
int main()
{
    int t,n,i,j,i1,j1,i2,j2,k,l,k1,l1,k2,l2;
    long long int maxsum,maxsum1,maxsum2,minsum,minsum1,minsum2,minn,maxx;
    bool flg;
    scanf("%d",&t);
    while(t--)
    {
        flg = true;
        maxsum = maxsum1 = maxsum2 = minsum = minsum1 = minsum2 = minn = maxx = 0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)  
        {
            scanf("%d",&arr[i]);
            if(arr[i] < 0)
                flg = false;
        }
        
        node res = MaxSumArray(1,n); // [1,n] incl.
        i = res.Imax;
        j = res.Jmax;
        //[i,j]  incl.
        if(i==1 && j==n)
        {
            //all positive case incl.
            if(flg)
            {
                //all +ve
                minn = min(arr[1],arr[n]);
                if(minn == arr[1])
                {
                    for(int var=2;var<=n;var++)
                        maxsum += arr[var];

                    cout<<maxsum - minn<<endl;
                }
                else
                {
                    for(int var=1;var<=n-1;var++)
                        maxsum += arr[var];

                    cout<<maxsum - minn<<endl;
                }
            
            }
            else
            {


                minn = min(arr[1],arr[n]);
                if(minn == arr[1])
                {
                    for(int var=2;var<=n;var++)
                        maxsum += arr[var];

                    cout<<maxsum - minn<<endl;
                }
                else
                {
                    for(int var=1;var<=n-1;var++)
                        maxsum += arr[var];
                    //ans = maxsum - minn
                }
                //+ve & -ve both
                res = MinSumArray(1,n);
                minsum = res.max_sum;
                k = res.Imax;
                l = res.Jmax;
                //[k,l]
                /** left range [1,k-1] && [l+1,n] **/
                if(k-1 >=1)
                {
                    res = MaxSumArray(1,k-1);
                    maxsum1 = res.max_sum;
                    i1 = res.Imax;
                    j1 = res.Jmax; 
                }
                if(l+1 <= n)
                {
                    res = MaxSumArray(l+1,n);
                    maxsum2 = res.max_sum;
                    i2 = res.Imax;
                    j2 = res.Jmax;
                }
                maxx = max(maxsum1,maxsum2);
                cout<<max(maxx - minsum,maxsum - minn)<<endl;

            }


        }
        else
        {
            //all negative case incl.
            maxsum = res.max_sum;
            //left range [1,i-1] && [j+1,n]
            if(i-1 >= 1)
            {
                res = MinSumArray(1,i-1);
                minsum1 = res.max_sum;
                k1 = res.Imax;
                l1 = res.Jmax;
            }
            if(j+1 <= n)
            {
                res = MinSumArray(j+1,n);
                minsum2 = res.max_sum;
                k2 = res.Imax;
                l2 = res.Jmax;
            }
            minn = min(minsum1,minsum2);
            cout<<maxsum - minn<<endl;
        }
    }
    return 0;
}
