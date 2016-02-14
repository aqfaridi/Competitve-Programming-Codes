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
int main()
{
    int t,m,n,L,found;
    bool flag;
    string s1,s2,txt,pat;
    scanf("%d",&t);
    while(t--)
    {
        map<int,int> mymap;
        cin>>s1>>s2;
        cin>>L;
        n = s1.length();
        m = s2.length();
        for(int i=1;i<=L;i++)
        {
            found = 0;
            flag = false;
            for(int j=0;j<=m-i;j++)
            {                
               found = 0; 
               txt = s1.substr(j,i);
               //cout<<txt<<endl;
               //cout<<j<<" "<<j+i-1<<" ";               
               found = s2.find(txt,found);
        
               if(found!=-1)
               {
                    flag = true;
                    mymap[i]++;
                    while(found<m)
                    {
                        found = s2.find(txt,found+1);
                        //cout<<found<<endl;
                        if(found!=-1)
                            mymap[i]++;
                        else
                            break;
                    }
               }
               //cout<<found<<endl;
               //KMP(txt,s2,i+1,m);  
            }
            if(!flag)
                mymap[i] = 0;
        }
        map<int,int>::iterator it;
        for(it = mymap.begin();it!=mymap.end();it++)
            cout<<(*it).second<<" ";
        cout<<endl;
    }
    return 0;
}

