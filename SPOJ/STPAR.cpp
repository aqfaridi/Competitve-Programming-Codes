#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>
#define MAX 1010
using namespace std;
int input[MAX];
int main()
{
    int n,count;
    bool b;
    while(1)
    {
        stack<int> mystack;
        b=true;
        count=1;
        scanf("%d",&n);
        if(n==0)
            break;
        for(int i=0;i<n;i++)        
        {
            scanf("%d",&input[i]);        
        }
        //for(int i=0;i<n;i++)
          //  cout<<input[i]<<" ";
        
        for(int i=0;i<n;i++)
        {
            //cout<<input[i]<<" ";
            while(!mystack.empty() && mystack.top() == count)
            {count++; mystack.pop();}

            if(input[i] == count)
                count++;
            else if(!mystack.empty() && (input[i] > mystack.top()) )
            { b = false;break;}
            else 
            {
                mystack.push(input[i]);
            }

        }
        if(b)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

