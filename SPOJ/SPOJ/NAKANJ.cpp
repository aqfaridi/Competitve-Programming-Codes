#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;
int minn = INT_MAX;
int a[9][9]={0};// to avoid cycle
//int firsttime = 23;
void recursion(int x1,int y1,int x2,int y2,int cnt)
{
    //cout<<"hello";
    if((x1==x2) && (y1==y2))
    {
        //cout<<cnt<<endl;
        if(cnt < minn)
            minn = cnt;

        return ;
    }
  
    /******* 8 directions******/
    a[x1][y1] = 1;
    if((x1+2 <=8) && (y1+1<=8) && a[x1+2][y1+1]==0)
    {   
        //cout<<"--^  ";
        if(cnt+1 < minn) 
            recursion(x1+2,y1+1,x2,y2,cnt+1);
    }
    if((x1+2<=8) && (y1-1 >=1) && a[x1+2][y1-1]==0)
    {
        //cout<<"--, ";
        if(cnt+1 < minn)
            recursion(x1+2,y1-1,x2,y2,cnt+1);
    }
    if((x1+1<=8) && (y1+2<=8) && a[x1+1][y1+2]==0)
    {
       // cout<<"-^^  ";
        if(cnt+1 < minn)
            recursion(x1+1,y1+2,x2,y2,cnt+1);
    }
    if((x1+1<=8) && (y1-2>=1) && a[x1+1][y1-2]==0)
    {
        //cout<<"-,,  ";
        if(cnt+1 < minn)
            recursion(x1+1,y1-2,x2,y2,cnt+1);
    }
    if((x1-2>=1) && (y1+1<=8) && a[x1-2][y1+1]==0)
    {
        //cout<<"^--  ";
        if(cnt+1 < minn)
            recursion(x1-2,y1+1,x2,y2,cnt+1);
    }
    if((x1-2>=1) && (y1-1>=1) && a[x1-2][y1-1]==0)
    {
        //cout<<",--  ";
        if(cnt + 1 < minn)
            recursion(x1-2,y1-1,x2,y2,cnt+1);
       // firsttime = 23;
    }
    if((x1-1>=1) && (y1+2<=8) && a[x1-1][y1+2]==0)
    {
        //cout<<"^^-  ";
        if(cnt +1 < minn)
            recursion(x1-1,y1+2,x2,y2,cnt+1);
    }
    if((x1-1>=1) && (y1-2>=1) && a[x1-1][y1-2]==0)
    {
        //if(firsttime==23)
        //{cout<<"====>"<<cnt;
          //  cout<<"here i am starting======="<<endl;}
        //cout<<",,-  ";
        
        if(cnt+1 < minn)
            recursion(x1-1,y1-2,x2,y2,cnt+1);
    }
    //firsttime++;
    a[x1][y1] = 0;

}
int main()
{
    //ios::sync_with_stdio(false);
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

        memset(a,0,sizeof a);
        minn = INT_MAX;
        scanf("%s %s",str1,str2);
        x1 = m[str1[0]];
        y1 = str1[1]-'0';
        x2 = m[str2[0]];
        y2 = str2[1]-'0';
        //cout<<x1<<" "<<y1<<endl;
        //cout<<x2<<" "<<y2<<endl;
        recursion(x1,y1,x2,y2,0); 
        printf("%d\n",minn);
    }
    return 0;
}

