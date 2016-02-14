#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
double uniform(double a,double b)
{
    return rand()/ (RAND_MAX + 1.0) * (b-a) + a ;
}
int main()
{
    int T,N,H,S;
    scanf("%d%d%d",&T,&N,&H);
    //srand(time(NULL));
    while(T--)
    {
        srand(time(NULL));
        for(int j=0;j<N;j++)
        {  
             char result[15];             
             int length = (int)uniform(8.0,12.0) ;  
     
             for (int i = 0; i < length; i++)             
                result[i] = (char)(uniform(97.0,122.0));  
                //result[i] = (char)(((double) rand()/(RAND_MAX+1))*(122-96+1) + 96);
             
             result[length]='\0'; 
            printf("%s\n",result);
            fflush(stdout);
        }
        scanf("%d",&S);
        fflush(stdin);
    }
    return 0;
}

