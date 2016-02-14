#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int main()
{
    int t,l,x;
    int a1[26],a2[26];
    string str,s1,s2;
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        l = str.length();
        if((l&1))
        {
                       
            for(int i=0;i<l/2;i++) 
                a1[str[i]-'a'] += 1;
                         
            for(int i = l/2+1;i<l;i++)
                a2[str[i]-'a'] += 1;
           
            for(x=0;x<26;x++)
                if(a1[x] != a2[x])
                    break;
            if(x!=26)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
        else
        {
            for(int i=0;i<l/2;i++) 
                a1[str[i]-'a'] += 1;
                         
            for(int i = l/2;i<l;i++)
                a2[str[i]-'a'] += 1;
           
          
            for(x=0;x<26;x++)
            {
                if(a1[x] != a2 [x])
                {
                    //cout<<a1[x]<<" "<<a2[x]<<endl;
                    break;
                }
            }
            if(x!=26)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
                              
        }
        
    }
    return 0;
}

