#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
    int t,n,m,k,star,dot;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        int arr[n][2];
        //cout<<n<<" "<<m<<endl; 
        for(int i=0;i<n;i++)
        {
            star=0;dot=0;
            for(int j=0;j<m+1;j++)
            {
                scanf("%c",&ch);
           //     cout<<ch<<" ";
                if(ch=='*')
                    star++;
                else if(ch=='.')
                    dot++;
                   
            }
           // cout<<endl;
            arr[i][0]=star;
            arr[i][1]=dot;
        }
        int temp1,temp2;
      /*  for(int i=0;i<n;i++)
        {
            
           cout<<arr[i][0]<<" "<<arr[i][1];
            cout<<endl;
        }
        */
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][1] > arr[j][1])
                {
                    temp1=arr[i][1];
                    arr[i][1]=arr[j][1];
                    arr[j][1]=temp1;
                    temp2=arr[i][0];
                    arr[i][0]=arr[j][0];
                    arr[j][0]=temp2;
                }

            
            
            }
        }

   /*     for(int i=0;i<n;i++)
        {
          
            cout<<arr[i][0]<<" "<<arr[i][1];
            cout<<endl;
        }
    */
        int temp;
        for(int i=0;i<k;i++)
        {
            if(arr[i][1] > arr[i][0])
            {
                temp=arr[i][1];
                arr[i][1]=arr[i][0];
                arr[i][0]=temp;

                //sum += arr[i][0];
            }
            else
            {
                int profit=arr[i-1][0];
                int loss=arr[i][0];
                int nowi=i;
                //loss condition
                if(profit >= loss)
                {
                    for(;i<k;i++)
                    {
                        temp=arr[nowi][0];
                        arr[nowi][0]=arr[nowi][1];
                        arr[nowi][1]=temp;
                            
                    } 
                    //sum += arr[nowi][0];
                }
                else
                {

                    for(;i<k;i++)
                    {
                        temp=arr[nowi-1][0];
                        arr[nowi-1][0]=arr[nowi-1][1];
                        arr[nowi-1][1]=temp;

                    } 

                   // sum += arr[nowi-1][0];
                }
            }

        }
        
    int sum=0;    
    for(int i=0;i<n;i++)
        sum += arr[i][0];
    
    printf("%d\n",sum);

    
        
    }
    return 0;
}
