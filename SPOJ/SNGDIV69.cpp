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
bool cmp(char a,char b)
{
    return (a>b);
}
string str,num,desc,asc,diff;
void make_diff(int l)
{
    int temp;
    for(int i=l-1,j;i>=0;i--)
    {
        temp = desc[i]-asc[i];
        if(temp < 0)
        {
            j = i-1;
            while(j>0 && desc[j]=='0')
            {
                desc[j] = '9';
                j--;
            }
            
            temp = 10 + (desc[i]-'0');
            desc[j] = (desc[j] - 1);
            diff[i] = '0' + (temp - (asc[i]-'0'));
        }
        else
            diff[i] = temp+'0';
    }  
}
bool isONP(int l)
{
    for(int i=0;i<l;i++)
        if(diff[i]!='0')
            return 1;

    return 0;
}
bool isDiv(int d,int l)
{
    int rem = 0;
    for(int i=0;i<l;i++)
    {
        rem = rem*10 + (diff[i]-'0');
        rem %= d;
    }
    
    if(rem)
        return 0;
    else
        return 1;

}
int main()
{
    int t,n,l;
    bool ONP,magic,b6,b9;
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(n--)
        {
            cin >> str;
            num = str;
            l = str.length();
            sort(str.begin(),str.end());
            asc = str;
            sort(str.begin(),str.end(),cmp);
            desc = str;       
            make_diff(l);
       
            b6 = isDiv(6,l);
            b9 = isDiv(9,l);
            if(b6 && b9)
                magic = true;
            else
                magic = false;
       
            ONP = isONP(l);

            if(magic)
            {
                cout<<"Y";
                if(ONP)
                    cout<<"ONP";
                else
                    cout<<"ZER";
            }
            else
            {
                cout<<"N";
                if(ONP)
                    cout<<"ONP";
                else
                    cout<<"ZER";

                if(!b6)
                    cout<<"LTN";
                else if(!b9)
                    cout<<"GTN";
                else
                    cout<<"EQL";
            }
            cout<<endl;
        }
    }
    
    return 0;
}
