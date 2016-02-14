#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,l,a,b,c,cntr;
    double D;
    char str[60],store[60];
    char* ch;
    scanf("%d",&t);
    while(t--)
    {
        a=b=c=0;cntr=0;
        scanf("%s",str);
        strcpy(store,str);
        //printf("%s",store);
        ch = strtok(str,"-+");
        while(ch != NULL)
        {
            cntr++;
            //cout<<ch<<endl;
            l = strlen(ch) ;
            if(l>3 && (cntr==1)&& (ch[l-1] == 'x' && ch[l-2]=='*' && ch[l-3]=='x' && ch[l-4]=='*'))
                a = atoi(ch);
            else if(l==3 && (cntr==1) && (ch[l-1] == 'x' && ch[l-2]=='*' && ch[l-3]=='x'))
                a = 1;

            else if(l>2 && (cntr==2) && (ch[l-1] == 'x' && ch[l-2]=='*' && ch[l-3]!='x'))
                b = atoi(ch);
            else if(l==1 && (cntr==2) && (ch[l-1] == 'x'))
                b = 1;

            else if(l>2 && (ch[l-1]=='0' && ch[l-2]=='=' && ch[l-3]!='x')) 
                c = atoi(ch);

            else if(l>5 && (cntr==1) && (ch[l-1]=='0' && ch[l-2]=='=' && ch[l-3]=='x' && ch[l-4]=='*' && ch[l-5]=='x')) 
                a = atoi(ch);
            else if(l==5 && (cntr==1) && (ch[l-1]=='0' && ch[l-2]=='=' && ch[l-3]=='x' && ch[l-4]=='*' && ch[l-5]=='x')) 
                a = 1;
            
            else if(l==3 && (cntr==2) && (ch[l-1]=='0' && ch[l-2]=='=' && ch[l-3]=='x')) 
                b = 1;

            else if(l>3 && (cntr==2) && (ch[l-1]=='0' && ch[l-2]=='=' && ch[l-3]=='x' && ch[l-4]=='*'))
                b = atoi(ch);
      
            ch = strtok(NULL,"-+");
        }
        int pos1=-1,pos2=-1,sign1=1,sign2=1;
        for(int i=0;store[i];i++)
        {
            //cout<<store[i];
            if(store[i]=='-')
            {
                pos1=i;
                sign1=-1;
            }
            else if(store[i]=='+')
            {
                pos2=i;
                sign2 = 1;
            }
        }
        if(pos1!=-1 && pos2!=-1)
        {
            if(pos1<pos2)
                b = -1*b;
            else
                c = -1*c;
        }
        else if(pos1!=-1 && pos2==-1)
        {
            b = -1*b;
            c = -1*c;
        }

        //cout<<a<<" "<<b<<" "<<c<<endl; 
         D = (b*b-4*a*c);
         if(D==0)
             printf("Equal roots.\n");
         else if (D>0)
             printf("Distinct real roots.\n");
         else if (D<0)
             printf("Imaginary roots.\n");
    }
    return 0;
}

