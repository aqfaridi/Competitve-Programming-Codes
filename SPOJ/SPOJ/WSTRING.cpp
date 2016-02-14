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
int main()
{
    int t,l,maxx,index,strcount;
    long long sum;
    char str[MAX];
    int freq[26],arr[MAX];
    scanf("%d",&t);
    while(t--)
    {
        index = 0;
        strcount=0;
        scanf("%s",str);
        char* ch = strtok(str,"#");
        while(ch != NULL)
        {
            strcount++;
            memset(freq,0,sizeof(freq));
            maxx = 0;
            //cout<<ch<<endl;
            l = strlen(ch);
            //cout<<l<<endl;
            for(int i=0;i<l;i++)
                freq[ch[i]-'a']++;
            for(int i=0;i<26;i++)
            {
                if(freq[i] > maxx)
                    maxx = freq[i];
            }
            arr[index++] = maxx;
           
            ch = strtok(NULL,"#");
        } 
        if(strcount <= 3)
        {
            cout<<0<<endl;
            continue;
        }
        sum = 0;
        for(int i=0;i<index;i++)
        {
            //maximum 4 consecutive sum
            if((i+3)<index  &&  (arr[i] + arr[i+1] + arr[i+2] + arr[i+3]) > sum)
                sum = arr[i] + arr[i+1] + arr[i+2] + arr[i+3];//cout<<arr[i]<<" ";
        }
        cout<<sum+3<<endl;
    }
    return 0;
}

