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
int nof_matches = 0;
void KMP(string txt,string pat,int n,int m)
{
    //Longest proper Prefix Suffix Array
    LPS(pat,m);
    bool flag;
    int i=0,j=0;
    while(i < n)
    {
        flag = false;
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
            //cout<<"pattern found at index="<<i-j<<endl;
            flag = true;
            nof_matches += 1;
            j = lps[j-1];              //txt:ABCABCA     pat:ABCABC
        }

        if(i !=0 && (i % m == 0))
            if(!flag)
                break;
    }
}
int n;
string str;
bool check(string sub,int m)
{
    char a[100010],b[100010];
    int i,j=0;
    for(i=0;i<m;i++)
        a[i] = str[i];
    a[i] = '\0';
    //cout<<sub<<endl;
    //cout<<str<<endl;
    while(i<n)
    {
        while(j<m)
            b[j++] = str[i++];
        b[j] = '\0'; 
        //cout<<j<<" "<<b<<endl;
        j = 0;
        if(strcmp(a,b) != 0) return false;
    }
    return true;
}

vector<int> diV;
void findDiv(int n)
{
    for(int i=1;i<=n/2;i++)
        if(n % i == 0)
            diV.push_back(i);
    
    diV.push_back(n);
}
int main()
{
    int index,cnt,t,size,quotient;
    string sub;
    char copy[100010];
    while(1)
    {
        diV.clear();
        scanf("%s",copy);
        str = copy;
        if(str[0]=='*')
            break;
        n = str.length();
        findDiv(n);
        size = diV.size();
        for(int i=0 ; i<size ; i++)
        {
            nof_matches = 0;
            quotient = n / diV[i];
            sub = str.substr(0,diV[i]);
            
            if(check(sub,diV[i]))
            {
                printf("%d\n",quotient);
                break;
            }
        }
    }
    return 0;
}
