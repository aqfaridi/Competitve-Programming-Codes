/*******************************
// Name : Abdul Qadir Faridi
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

#define si(n)                       scanf("%d",&n)
#define sll(n)                      scanf("%lld",&n)
#define sf(n)                       scanf("%f",&n)
#define ss(str)                     scanf("%s",str)
#define sd(n)                       scanf("%lf",&n)
#define INF                         INT_MAX
#define LINF                        (LL)1e18
#define maX(a,b)                    ((a)>(b)?(a):(b))
#define miN(a,b)                    ((a)<(b)?(a):(b))
#define abS(x)                      ((x)<0?-(x):(x))
#define    forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define pn()                        printf("\n")
#define pi(n)                       printf("%d",n)
#define pll(n)                      printf("%lld",n)
#define pd(n)                       printf("%lf",n)
#define ps(str)                     printf("%s",str)

//macros stl

#define mp                          make_pair
#define tri(a,b,c)                  mp(a,mp(b,c))
#define pb                          push_back
#define fill(a,v)                   memset(a,v,sizeof a)
#define all(x)                      x.begin(),x.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define findval(arr,val)            (lower_bound(all(arr)),val)-arr.begin()
#define clr(a)                    memset(a,0,sizeof a)

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

//FAST io

#define input(n) read(&n)
/**
void read(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}
**/
double sq(double x)
{
    return (x*x);
}
char str[100000];
long double num[10000][2];
int main()
{
    int I,l,j,row=-1,flag=0;
    char line;
    while(1)
    {
        flag = scanf("%[^\n]s",str);
        
        if(flag == -1)
            break;

        else if(flag==0)
        {
            line = getchar();
            continue;
        }

        row++;
        I = 0;
        char *ch = strtok(str,"()");
        while(ch != NULL)
        {
            I++;
            //printf("%s\n",ch);
            if(I==2)
            {
                sscanf(ch,"%Lf, %Lf",&num[row][0],&num[row][1]);
                //cout<<num[row][0] <<" "<<num[row][1]<<endl;
            }
            ch = strtok(NULL,"()");
        }
        line = getchar();
    }
    long double sum = 0.0;
    for(int i=1;i<=row;i++)
    {
        //cout<<num[i-1][0]<<" "<<num[i-1][1]<<endl;
        //cout<<num[i][0]<<" "<<num[i][1]<<endl;
        sum += sqrt ( sq(num[i][1]-num[i-1][1]) + sq(num[i][0]-num[i-1][0]) );         
    
        printf("The salesman has traveled a total of %.3Lf kilometers.\n",sum);
    }

    return  0;
}


