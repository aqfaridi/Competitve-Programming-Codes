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
#define MAX 1010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int lps[MAX];
void LPS(string pat,int m)
{
    int i = 1;
    int j = 0;
    while(i<m)
    {
        if(pat[i] == pat[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if(j != 0)        //AABAAAB 0101223
                j = lps[j-1];
            else              //ABCDA   00001  
            {   lps[i] = 0; i++; }
        }
    }
}
void KMP(string txt,string pat,int n,int m)
{
    //Longest proper Prefix Suffix Array
    LPS(pat,m);

    int i=0,j=0;
    while(i < n)
    {
        if(txt[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0)  //(A^k)B  case //txt:AABAAAB    pat:AAB
                j = lps[j-1];   
            else
                i++;
        }

        if(j == m)
        {
            cout<<"pattern found at index="<<i-j<<endl;
            j = lps[j-1];              //txt:ABCABCA     pat:ABCABC
        }
    }
}
int main()
{
    int t,m,n;
    string txt,pat;
    scanf("%d",&t);
    while(t--)
    {
        cin>>txt>>pat;
        n = txt.length();
        m = pat.length();
        KMP(txt,pat,n,m);        
    }
    return 0;
}

