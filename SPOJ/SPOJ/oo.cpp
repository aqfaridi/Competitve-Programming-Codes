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

//Preprocessor directives

#define MAX 1000010
#define MOD 1000000007
#define gc getchar_unlocked

//macros input-output


//debug

#define debug                       if(1)
#define debugoff                    if(0)    

//constants

#define PI                          M_PI
#define E                           M_E
using namespace std;

//typedef

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<int,pii> tri;

int arr[300010];    
LL pref[300010];
int main()
{
    int t;
    int n;
    LL sum = 0;
    int posi=0,posj=0;
    cin>>n;
    LL maxx = -INT_MAX;
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    if(n==2)
    {
        sum = arr[1]+arr[2];
        cout<<sum<<" "<<0<<endl;
        cout<<endl;
        return 0;
    }
    memset(pref,0,sizeof pref);
    if(arr[1]>=0)
        pref[1] = arr[1];

    for(int i=2;i<=n;i++)
    {
        if(arr[i]>0)
            pref[i] = arr[i] + pref[i-1];
        else
            pref[i] = pref[i-1];
    }  
  
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
        
            if(arr[i]==arr[j])
            {
                sum  = 0;
                if(arr[i]<0)
                    sum = (arr[i]+arr[j]);
                /**
                for(int x=i;x<=j;x++)
                {
                    //cout<<arr[x]<<endl;
                    if(arr[x]>0)
                        sum += arr[x];
                }**/
                sum += pref[j] - pref[i-1];
                if(sum > maxx)
                {
                        posi = i;
                        posj = j;
                        maxx = sum;
                }                
            }
        }
    }
    int cut=0;
    for(int x=posi+1;x<posj;x++)
        if(arr[x]<=0)
            cut++;
    LL kk=0;
    
    kk = (posi-1) + (n-posj) + cut;
    cout<<maxx<<" "<<kk<<endl;
    for(int i=1;i<=(posi-1);i++)
        cout<<i<<" ";
    for(int x=posi+1;x<posj;x++)
        if(arr[x]<=0)
            cout<<x<<" ";
    for(int i=posj+1;i<=n;i++)
        cout<<i<<" ";
    cout<<endl;
    return  0;
}

