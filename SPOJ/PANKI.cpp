#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
int isvowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
}
int main()
{
    string sub,str;
    bool flag[1000010];
    int t,l;
    char ch;
    getline(cin,str);
    stringstream(str) >> t;
    while(t)
    {
        memset(flag,0,sizeof(flag));
        getline(cin,str);
        l = str.length();
        if(l==0)
            continue;
        flag[0] = true;
        for(int i=1;i<l;i++)
            if(str[i-1]==' ' && isalpha(str[i]))
                flag[i] = true;
        for(int i=0;i<l;i++)
        {
            if(str[i]==' '){cout<<' ';continue;}
            ch = str[i];
            if(isvowel(ch)) ch = toupper(ch);
            else    ch = tolower(ch);

            if(flag[i])
                cout<<(char)toupper(str[i]);
            else
                cout<<ch;
        }
        if(t!=1)
            cout<<endl<<endl;
        t-=1;
    }
    return 0;
}
