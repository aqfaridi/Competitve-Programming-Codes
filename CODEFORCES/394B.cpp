#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
map<string,int> mp;
char str[1000010],sub[1000010];
int main()
{
    ios::sync_with_stdio(false);
    int p,x,l,carry,z,rem,cnt,t;
    string s;
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>p>>x;
        if(p==1 && x>1)
        {
            cout<<"Impossible"<<endl;;
            continue;
        }
        if(p==1 && x==1)
        {
            cout<<1<<endl;
            continue;
        }
        for(int ld=1;ld<=9;ld++)
        {
            str[p] = '\0';
            str[p-1] = ld+'0';
            carry = 0;
            for(int i=p-1;i>0;i--)
            {
                z = (str[i]-'0')*x;
                rem = (z+carry)%10;
                carry = (z+carry)/10;     
                str[i-1] = rem+'0';
            }
            cnt = 0;
            if(str[0] != '0')
            {
                
                s = (string)str;            
                l = s.length();
                sub[0] = str[p-1];
                for(int i=1;i<l;i++)
                    sub[i] = str[i-1];
                sub[p] = '\0';
        carry = 0;
                for(int i=l-1;i>=0;i--)
                {
                    z = (s[i]-'0')*x;
                    rem = (z+carry)%10;
                    carry = (z+carry)/10;
                    if(rem == sub[i]-'0')
                        cnt++;
                }
                if(carry == 0 && cnt==p)
                {
                    
                    mp[s]++;
                }
            }
        }
        
        if(mp.size() > 0)
        {
            map<string,int>::iterator it=mp.begin();
            cout<<(it->first)<<endl;
        }
        else
            cout<<"Impossible"<<endl;
    }
    return 0;
}
