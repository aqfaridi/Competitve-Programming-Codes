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

using namespace std;

//typedef

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<int,pii> tri;

    
int main()
{
    int t;
    LL n,nn;
    cin>>n;
    int len,rem,maxx;
    int steps=0;
    while(n)
    {   
        maxx = 0;
        steps++;
        nn = n;
        while(nn>0)
        {
            rem = nn%10;
            if(rem > maxx)
                maxx = rem;
            nn/=10;
        }
        n -= maxx;
    }
    cout<<steps<<endl;
    return  0;
}

