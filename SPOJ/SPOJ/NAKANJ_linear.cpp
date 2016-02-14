#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;
int minn = INT_MAX;
void calc(int b,int d,int e,int f,int g,int h,int x1,int y1,int x2,int y2)
{

    for(int a=0;a<=8;a++)
    {
        for(int c=0;c<=8;c++)
        {
           
           if((3*a - 3*c - 5*e + 5*f - 4*g + 4*h) == (2*(y2-y1)-(x2-x1)))
           {
               if((a+b+c+d+e+f+g+h) < minn)
                    minn = (a+b+c+d+e+f+g+h);
           }             
        }
    }
}
void calculate(int x1,int y1,int x2,int y2)
{
    int arr[MAX];
    for(int b=0;b<=8;b++)
    {
        for(int d=0;d<=8;d++)
        {
            for(int e=0;e<=8;e++)
            {
                arr[k++] = 3*b -3*d +4*e;             
             //   if((3*b - 3*d + 4*e - 4*f + 5*g -5*h) == (2*(x2-x1)-(y2-y1)))
              //  {
                //     calc(b,d,e,f,g,h,x1,y1,x2,y2);
                //}
            }               
            
        }
    }
    sort(arr,arr+k);
    for(int f=0;f<=8;f++)
    {
        for(int g=0;g<=8;g++)
        {
            for(int h=0;h<=8;h++)
            {
                
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int t,x1,y1,x2,y2;
    map<char,int> m;
    char ch = 'a';
    char str1[2],str2[2];
    for(int i=1;i<=8;i++)
    {
        m.insert(make_pair(ch,i));
        ch++;
    }
    scanf("%d",&t);
    while(t--)
    {

        minn = INT_MAX;
        scanf("%s %s",str1,str2);
        x1 = m[str1[0]];
        y1 = str1[1]-'0';
        x2 = m[str2[0]];
        y2 = str2[1]-'0';
        //cout<<x1<<" "<<y1<<endl;
        //cout<<x2<<" "<<y2<<endl;
        calculate(x1,y1,x2,y2); 
        printf("%d\n",minn);
    }
    return 0;
}

