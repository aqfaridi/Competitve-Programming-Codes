#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  
    int t,k,i,j,l;
    scanf("%d",&t);
    char a[2][3],c[18][4];
    int b[2],d[16];
    for(i=0;i<t;i++) 
    {
        int f,max,ind,index;
        for(j=0;j<16;j++)
        {
            d[j]=0;
        }
        scanf("%s %s %d %d",a[0],a[1],b[0],b[1]);
        if(b[0]>b[1])
        {
            strcpy(c[0],a[0]);
            d[0]++;
            ind=0;
        }
        else
        {
            strcpy(c[0],a[1]);
            d[0]++;
            ind=0;
        }
        for(l=1;l<16;l++)
        {
            scanf("%s %s %d %d",a[0],a[1],b[0],b[1]);
            if(b[0]>b[1])
            {
                f=0;
                for(j=0;j<=ind;j++)
                {
                
                    if(strcmp(c[j],a[0])==0)
                    {
                        d[j]++;
                        f=1;
                        break;
                    }
                }
                if(f==0)
                {
                    ind++;
                    strcpy(c[++ind],a[0]);
                    d[ind]++;
                }
            
            
        }
        else
        {
            f=0;
             for(j=0;j<=ind;j++)
            {
                
                if(strcmp(c[j],a[1])==0)
                {
                    d[j]++;
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                
                strcpy(c[++ind],a[1]);
                d[ind]++;
            }
            
        }
        }
        max=d[0];
        index=0;
        for(k=0;k<16;k++)
        {
            if(d[k]>max)
            {
                max=d[k];
                index=k;
            }
        }
        printf("%s\n",c[index]);
    }
    return 0;
}
 
