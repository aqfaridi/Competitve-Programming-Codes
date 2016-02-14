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
void LPS(char* pat,int m)
{
    //cout<<pat<<endl;
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
  //  for(int i=0;i<9;i++)
    //    cout<<lps[i]<<" ";
    //cout<<endl;
}
void KMP(char* pat,int m)
{
    //Longest proper Prefix Suffix Array
    LPS(pat,m);
    char txt_i;
    int i=0,j=0;
    while(1)
    {
        txt_i = getchar();     
        if(txt_i == '\n') break;
        
        while(1) //until utilized : taking care of i
        {

            if(txt_i == pat[j])
            {
                j++;

                //cout<<txt_i<<"in"<<j<<endl;
                if(j == m)
                {
                    printf("%d\n", (i-j)+1);
                    j = lps[j-1];              //txt:ABCABCA     pat:ABCABC
                    break;
                }
                break;//insert break in place of i++;
            }
            
            else
            {
                if(j != 0)  //(A^k)B  case //txt:AABAAAB    pat:AAB
                    j = lps[j-1];   
                else
                    break;
            }    
            //cout<<txt_i<<" "<<j<<"out"<<endl;
        }
        i++;
        
    }
}
int main()
{
    int t,m,n;
    char *pat;
    char ch;
    //scanf("%d",&t);
    while(scanf("%d",&m)==1)
    {   
        ch = getchar();
        pat = new char[m+1];        
        scanf("%[^\n]s",pat);
        ch = getchar();
        //cout<<pat<<endl;
        KMP(pat,m);
        printf("\n");
        delete[] pat;
    }
    return 0;
}

