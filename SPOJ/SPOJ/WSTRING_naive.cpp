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
    int t,l,len,maxx,index,ind,hashcnt,strcount;
    long long sum;
    char str[MAX],wstr[MAX];
    int freq[26],arr[MAX];
    scanf("%d",&t);
    while(t--)
    {
        index = 0;
       
        scanf("%s",str);
        l = strlen(str);
        for(int i=0;i<l;i++)
        {
            ind = 0;
            maxx = 0;
            hashcnt = 0;
            memset(freq,0,sizeof(freq));
            while(str[i] != '#' && str[i] != '\0')
            {
                wstr[ind++] = str[i++];
            }
            wstr[ind] = '\0' ;
            //cout<<wstr<<" "<<i<<endl;
            while(str[i] == '#')
            {
                hashcnt++;
                i++;
            }
            //cout<<i<<endl;
            i = i-1;
            //cout<<i<<endl;
       
            for(int j=0;wstr[j] != '\0';j++)
                freq[wstr[j]-'a'] += 1;

            for(int i=0;i<26;i++)
            {
                if(freq[i] > maxx)
                    maxx = freq[i];
            }
            arr[index++] = (maxx>0)?maxx:-1;

            if(hashcnt >=2)
                arr[index++] = -1;
           
        }
       // for(int i=0;i<index;i++)
         //   cout<<arr[i]<<" ";
        //cout<<endl;
        sum = 0;
        for(int i=0;i<index;i++)
        {
            //maximum 4 consecutive sum
            if((i+3)<index  &&  ((arr[i]>0) && (arr[i+1]>0) && (arr[i+2]>0) && (arr[i+3]>0)) && (arr[i] + arr[i+1] + arr[i+2] + arr[i+3]) > sum)
                sum = arr[i] + arr[i+1] + arr[i+2] + arr[i+3];//cout<<arr[i]<<" ";
        }
        (sum>0)?cout<<sum+3:cout<<0;
        cout<<endl;
    }
    return 0;
}

