#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int divide[10];
int nodigit[10];
int cnt;
void division(string str)
{
    int num,digit,l;
    l = str.length();
    for(int i = 0; i < l; i++) 
    {
        digit = str[i]-'0';
        nodigit[digit] += 1; //freq
        if(digit == 0)
            continue;
        if(divide[digit]==1 || divide[digit]==-1)
            continue;
        // maximum number of digit are 1-9
        num = 0;
        for(int j=0;j<l;j++)
        {
            num = num*10 + (str[j]-'0');
            num %= digit;
        }
        if(num==0)
            divide[digit] = 1;
        else
            divide[digit] = -1;
    }
}
int main()
{
    string str;
    while(getline(cin,str))
    {
        memset(divide,0,sizeof(divide));
        memset(nodigit,0,sizeof(nodigit));
        cnt = 0;
        division(str);
        for(int i=0;i<=9;i++)
        {
            //cout<<divide[i]<<" ";
            if(divide[i]==-1)
                divide[i]=0;
            //cout<<divide[i]<<" ";
        }
        //cout<<endl;
        for(int i=1;i<=9;i++)
        {
            //cout<<nodigit[i]<<" ";
            cnt += (nodigit[i]*divide[i]);
        }
        printf("%d\n",cnt);
    }
    return 0;
}

