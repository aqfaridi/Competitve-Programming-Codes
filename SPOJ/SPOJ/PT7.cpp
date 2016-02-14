#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int a[210],a1[210],e[210],e1[210];
    int t,n,rock,k,count,x,y;
    int stay1,stay2,mov1,mov2,hit1,hit2;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        k=0;x=0;y=0;
        stay1=1;stay2=1;
        mov1=1;mov2=1;
        hit1=0;hit2=0;
        memset(a,0,sizeof(a));
        memset(e,0,sizeof(e));
        memset(a1,0,sizeof(a1));
        memset(e1,0,sizeof(e1));
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            cin>>ch>>rock;
            //cout<<ch<<" "<<rock<<endl;
            if(ch=='A')
            {
              //  cout<<rock<<endl;
                a[k] = rock;
                //cout<<a[k];
                a1[x++] = rock;
            }
            else
             {
                 //cout<<rock<<endl;
                
                 e[k] = rock;
                 e1[y++] = rock;
             }
            
             k++;            
        }
        count=0;
        int xx=0,yy=0;
    //    for(int i=0;i<k;i++)
      //      cout<<a[i] <<" " <<e[i] << endl;

       // for(int i=0;i<4;i++)
         //   cout<<a1[i]<<" "<<e1[i] <<endl;

        for(int i=0;i<k;i++)
        {
            /*
            if(a1[i] < e1[i])
            {
                if(a[i]!=0)
                {}
                else
                {}
                
            }
            else 
            {*/
            
            if(hit1+hit2 == n)
                break;

                if(a[i]!=0)
                {
                    while(1)
                    {
                        if(mov1 == a1[xx])
                        {
                            if(mov2 !=e1[yy])
                                mov2 +=1;
                            hit1++;count++;xx++;break;
                        }
                        mov1 += 1;
                        count ++;
                        if(mov2 != e1[yy])
                            mov2 += 1;
                       //cout<<mov1<<" "<<mov2<<" "<<a1[xx]<<endl;
                        //if(mov1 == a1[xx]) 
                        //{hit1++;count++;xx++;break;}
                        //cout<<"jhi";   
                    }
                   // cout<<"count"<<count<<endl;

                }
                else
                {
                    while(1)
                    {
                        if(mov2 == e1[yy])
                        {
                            if(mov1 !=a1[xx])
                                mov1+=1;
                         hit2++;count++;yy++;break;
                        }

                        mov2 +=1;
                        count++;
                        if(mov1 != a1[xx])
                            mov1 += 1;
                        
                     //   cout<<"mov2="<<mov1<<" "<<mov2<<" "<<e1[yy]<<endl;
                        //if(mov2 == e1[yy])
                        //{hit2++;count++;yy++;break;}
                       // cout<<"hi";

                    }

                  //  cout<<"count="<<count<<endl;
                 }

            //}

        }
        cout<<count<<endl;
    }
    return 0;
}
