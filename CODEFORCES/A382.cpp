#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int main()
{
    int t,n,cnt1=0,cnt2=0;
    string str1,str2,s1="",s2="";
    cin>>str1>>str2;
    int l = str1.length();
    int i;
    for(i=0;i<l;i++)
    {
        if(str1[i]=='|')
            break;
        s1+= str1[i];
        cnt1++;
    }
    for(i++;i<l;i++)
        s2 += str1[i];
    
    cnt2 = l-cnt1-1;
    

    int l2 = str2.length();
    int diff = abs(cnt1-cnt2);
    l2 = l2 - diff;
   
    if(l2<0 || l2&1)
        cout<<"Impossible"<<endl;
    else
    {        
        for(int j=0;j<str2.length();j++)
        {
            if(s1.length() < s2.length())
            {
                s1 += str2[j];
            }
            else
            {
                s2 += str2[j];
            }
        }
        
        cout<<s1<<"|"<<s2<<endl;
    }
    return 0;
}
