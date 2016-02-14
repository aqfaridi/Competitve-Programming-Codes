#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <queue>
#include <utility>
#define MAX 100010
using namespace std;
queue<int> myqueue;
pair<long long,int> recursion(char* str,int i=0)
{
    char op = '+';
    long long a=0LL;

    for(;str[i]!=')';i++)
    {
        if(str[i]=='$')
            break;

        switch(str[i])
        {
            case '(':
                if(op=='+')
                {
                    
                    pair<long long,int> q  = recursion(str,i+1);
                    a += q.first;
                    
                    i = q.second ;
                } 
                else if(op=='-')
                {
                    
                    pair<long long,int> q  = recursion(str,i+1);
                    a -= q.first;
                    i = q.second ;
                    
                }
                else if(op=='*')
                {

                    pair<long long,int> q  = recursion(str,i+1);
                    a *= q.first;
                    i = q.second ;
                    
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
   
        }
   
    }
    pair<long long,int> p = make_pair(a,i);
    return p;
}
int main()
{
    int l,num;
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
    strcpy(chunk,str);
    str[l+2]='$';
    str[l+3]='\0';
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
    pair<long long,int> ans = recursion(str);
    cout<<ans.first<<endl;
    return 0;
}

