nclude <iostream>
#include <cstdio>
using namespace std;
int x=0;
int number(int **p,int n,int i,int j,int l,int r,int u,int b)
{
        
        if(p[i][j]==1 || i<0 || j<0 || j==n || i==n)
                    return 0;
            if(i==n-1 && j==n-1)
                        return x++;
                else 
                            {
                                            if(r==1)
                                                            {
                                                                                number(p,n,i,j+1,0,1,1,1);   //right
                                                                                       
                                                                                            }    
                                                        else if(l==1)
                                                                        {
                                                                                            number(p,n,i,j-1,1,0,1,1);         //left
                                                                                                      
                                                                                                        }
                                                                    else if(u==1)
                                                                                    {
                                                                                                        number(p,n,i,j-1,1,1,1,0);         //left
                                                                                                           
                                                                                                                        
                                                                                                                    }
                                                                                else if(b==1)
                                                                                                {
                                                                                                                    number(p,n,i,j-1,1,1,0,1);         //left
                                                                                                                        
                                                                                                                                    
                                                                                                                                }
                                                                                            
                                                                                        }
                    
}
int main() {
            
        int n;
            scanf("%d",&n);
                int **p;
                    p=new int*[n];
                        for(int i=0;i<n;i++)
                                    p[i]=new int[n];
                            
                            for(int i=0;i<n;i++)
                                        for(int j=0;j<n;j++)
                                                        scanf("%d",&p[i][j]);
                             
                                int sum=number(p,n,0,0,0,1,0,1);     
                                    
                                    printf("%d\n",x);
                                        
                                            return 0;
}
