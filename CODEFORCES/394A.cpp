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

#define MAX 100010
#define MOD 1000000007    
char str[1100],sub[1100];
int main()
{
    ios::sync_with_stdio(false);
    int t,n,maxx,minn;
    scanf("%s",str);
    strcpy(sub,str);
    int l = strlen(str);
    char *ch = strtok(str,"+=");
    int a,b,c,i=1;
    while( ch!=NULL)
    {
        if(i==1)
            a = strlen(ch);
        else if(i==2)
            b = strlen(ch);
        else if(i==3)
            c = strlen(ch);

        ch = strtok(NULL,"+=");
        i++;
    }
   //cout<<a<<" "<<b<<" "<<c<<endl;
   if(a+b == c)
   {
       printf("%s\n",sub);
       return 0;
   }
   else
   {
       if(a==1 && b==1 && c==1)
               {
                    cout<<"Impossible"<<endl;
                    return 0;
               }
        if(a+b +1 == c -1)
            {
                for(int i=1;i<=a+1;i++)
                    cout<<"|";
                cout<<"+";
                for(int i=1;i<=b;i++)
                    cout<<"|";
                cout<<"=";
                for(int i=1;i<c;i++)
                    cout<<"|";
            }
        else if(a+b -1 == c+1)
        {
                maxx = max(a,b);
                minn = min(a,b);
                for(int i=1;i<maxx;i++)
                    cout<<"|";
                cout<<"+";
                for(int i=1;i<=minn;i++)
                    cout<<"|";
                cout<<"=";
                for(int i=1;i<=c+1;i++)
                    cout<<"|";
        }
        else
            cout<<"Impossible"<<endl;
   }

    return 0;
}
