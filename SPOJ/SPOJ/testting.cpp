#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <queue>
#define MAX 100010
using namespace std;
queue<int> myqueue;
long long recursion(char* str,int cnt)
{
    int l = strlen(str),count=0;
    char op = '+';
    bool b = false;
    long long a = 0LL;
    for(int i=0;i<l;i++)
    {
        switch(str[i])
        {
            case '(':
                if(op=='+')
                {
                    cnt--;
                    a += recursion(str+i+1,cnt);
                    cout<<a<<endl<<endl;
                    while(cnt!=count)
                    {
                        if(str[i]==')')
                        {
                           count++;
                           i++;
                        }
                    }
                }
                else if(op=='-')
                {
                    cnt--;
                    a -= recursion(str+i+1,cnt);
                    cout<<a<<endl<<endl;
                       
                }
                else if(op=='*')
                {

                    cout<<a<<endl;
                    a *= recursion(str+i+1);
                    cout<<a<<endl<<endl;
                    while(str[i]!=')')
                        i++;
                }
                break;
 
            case '+':
                    op = '+';
                    break;
            case '-':
                    op = '-';
                    break;
            case '*':
                    op = '*';
                    break;
 
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                while(str[i]>=48 && str[i] <=57)
                    i++;
                i--;
                if(op=='+')
                {
                    a += myqueue.front();
                    cout<<a<<endl<<endl;
                    myqueue.pop();
                }
                else if(op=='-')
                {
                    a -= myqueue.front();
                    cout<<a<<endl<<endl;;
                    myqueue.pop();
                }
                else if(op=='*')
                {
                  
                    a *= myqueue.front();
                    cout<<a<<endl<<endl;;
                    myqueue.pop();
                }
                break;
            case ')':
                     b = true;
                     break;
        }
        if(b)
            break;
    }
    return a;
}
int main()
{
    int l,num,cnt=0;
    char str[MAX],chunk[MAX];
    scanf("%s",str+1);
    //strcpy(chunk+1,str+1);
    //cout<<chunk;
    l = strlen(str+1);
    //cout<<l<<endl;
    str[0] = '(';
    str[l+1] = ')';
    str[l+2] = '\0';
    //cout<<str<<endl;
    //printf("%s",str);
    //chunk[0]='(';
    //chunk[l]=')';
    //chunk[l+1]='\0';
    //cout<<chunk<<endl;
    for(int i=0;i<=l+1;i++)
        if(str[i]=='(')
            cnt++;
    strcpy(chunk,str);
    //cout<<chunk<<endl;
    char* ch = strtok(chunk,"+-*()");
    while(ch!=NULL)
    {
        myqueue.push(atoi(ch));
        ch = strtok(NULL,"+-*()");
    }
 
    /**
    while(!myqueue.empty())
    {
        cout<<myqueue.front()<<endl;
        myqueue.pop();
    }
    **/
    //char *chh = str+2;
    //cout<<chh[0]<<endl;
    cout<<cnt<<endl;
    cout<<recursion(str,cnt)<<endl;
    return 0;
}
 
