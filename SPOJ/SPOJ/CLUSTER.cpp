#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int t,n;
    string s;
    string str[20];
    bool b;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(str[i].compare(str[j]) < 0)
                {
                    str[i].swap(str[j]);
                }
            }
        }
        b=false;
        for(int i=0;i<n;i++)       
        {
            //cout<<str[i]<<endl;
            int a = str[i].find(s);
            if(a==0)
            {
                b=true;
                cout<<str[i];
                break;
            }
        }
        if(!b)
            cout<<s;
       
        cout<<endl;
    }
    return 0;
}
