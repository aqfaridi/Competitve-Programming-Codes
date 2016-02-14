#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <queue>
#define MAX 100010
using namespace std;
queue<long long> myqueue;
long long recursion(char* str)
{
    long long l = strlen(str);
    char op = '+';
    bool b = false;
    long long a=0LL;
    for(long long i=0;i<l;i++)
    {
        switch(str[i])
        {
            case '(':
                if(op=='+')
                {
                    a += recursion(str+i+1);    
                    while(str[i]!=')')
                        i++;
                }
                else if(op=='-')
                {
                    a -= recursion(str+i+1);
                    while(str[i]!=')')
                        i++;
                }
                else if(op=='/')
                {
                    a *= recursion(str+i+1);
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
                    myqueue.pop();
                }
                else if(op=='-')
                {
                    a -= myqueue.front();
                    myqueue.pop();
                }
                else if(op=='*')
                {
                    a *= myqueue.front();
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
    int l,num;
    long long res;
    char str[MAX],chunk[MAX];
    scanf("%s",str+1);
    //strcpy(chunk+1,str+1);
    //cout<<chunk;
    l = strlen(str+1);
    //cout<<l<<endl;
    //str[0] = '(';
    str[l+1] = ')';
    str[l+2] = '\0';
    //cout<<str<<endl;
    //printf("%s",str);
    //chunk[0]='(';
    //chunk[l]=')';
    //chunk[l+1]='\0';
    //cout<<chunk<<endl;
    strcpy(chunk,str);
    //cout<<chunk<<endl;
    char* ch = strtok(chunk,"+-*()");
    while(ch!=NULL)
    {
        cout<<ch<<endl;
        myqueue.push(atol(ch));
        ch = strtok(NULL,"+-*()");
    }
    
    
    while(!myqueue.empty())
    {
        cout<<myqueue.front()<<endl;
        myqueue.pop();
    }
    
    //char *chh = str+2;
    //cout<<chh[0]<<endl;
    res = recursion(str);
    cout<<res<<endl;
    return 0;
}

