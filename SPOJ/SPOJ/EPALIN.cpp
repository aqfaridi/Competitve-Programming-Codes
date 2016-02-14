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
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int lps[MAX];
void LPS(string pat,int m)
{
    int i=1;
    int j=0;
    while(i < m)
    {
        if(pat[i] == pat[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if(j != 0)
                j = lps[j-1];
            else
            {   lps[i] = 0; i++;}
        }
    }
}
int matched;
void KMP(string txt,string pat,int n,int m)
{
    LPS(pat,m);
    int i = 0 , j = 0 ;
    while(i < n)
    {
        if(txt[i] == pat[j])
        {
            i++;
            j++;
            matched = j;
            if(j==m)
                j = lps[j-1];
        }
        else
        {
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
}
int main()
{
    int m,n;
    string str,rev_str;
    while(getline(cin,str))
    {
        matched = 0;
        rev_str = str.substr(0);
        reverse(rev_str.begin(),rev_str.end());
        n = str.length();
        m = n;
        KMP(str,rev_str,n,m);
        cout<<str;
        if(matched >= m)
            cout<<endl;
        else
            cout << rev_str.substr(matched) << endl;
    }    
    return 0;
}
