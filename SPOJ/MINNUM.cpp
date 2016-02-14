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
    char s[100];
    string str;
    int l,r,q;
    bool b=false;
    while(1)
    {
        
        cin>>str;
        if(str.compare("-1")==0)
            break;
        //if(b)
          //  cout<<endl;
        //b = true;
        if(str.compare("0")==0)
        {   cout<<0<<endl; continue;}
        l = str.length();
        r = 0;q = 0;
        for(int i=0;i<l;i++)
        {
            r = r*10 + (str[i]-'0');
            s[i] = (r/9 + '0');
            r%=9;        
        }
        if(r!=0)
        {
            if(s[l-1]!='9')
            {
                s[l-1] = ((s[l-1]-'0') + 1)+'0';
                s[l] = '\0';
                if(s[0]!='0')
                    cout<<s<<endl;
                else
                    cout<<s+1<<endl;
            }
            else 
            {
                int k=l-1;
                while(s[k]=='9')
                {
                    s[k] = '0';
                    k--;
                }
                s[k]=((s[k]-'0') + 1)+'0';
                s[l] = '\0';
                if(s[0]!='0')
                    cout<<s<<endl;
                else
                    cout<<s+1<<endl;
            }
        }
        else
        {
            s[l] = '\0';
            if(s[0]!='0')
                cout<<s<<endl;
            else 
                cout<<s+1<<endl;
        }
        
    }
    return 0;
}


