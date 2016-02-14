#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int p[101];
int main()
{
    int n,x,count;
//    scanf("%d",&n);
    cin>>n;
    cout<<n<<endl;
   // int *p=new int[n];
    for(int i=0;i<n;i++)
    {p[i]=1;cout<<p[i]<<" ";}
    p[0]=0;
    for(int k=2;k<n;k++)
    {
        count=0;
        x=0;
        for(int i=1;;i++)
        {
           cout<<i<<" "; 
            if(p[i%n]==1)
            {
                cout<<endl<<x<<endl;
                x++;
                if(x==k)
                {p[i%n]=0;count++;x=0;cout<<endl<<count<<endl;}
                
            
            }

       
            if(count == (n-2))
                break;
        }
        if(count == (n-2) && p[12]==1)
           {cout<<"k="<<k<<endl;break;}
    
    }
 //  delete p;


    return 0;
}

