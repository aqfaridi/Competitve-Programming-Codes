#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#define MAX 1000001
using namespace std;
vector<pair<int,int> > nod(MAX,make_pair(0,-1));
int arr[MAX]; 
void nofDivisors()
{
    for(int i=1;i<MAX;i++)
    {
        for(int j=i;j<MAX;j+=i) 
        {
            // i is divisor of all j 
            nod[j].first += 1; 
        }
    }
    
    for(int i=1;i<MAX;i++)
    {
        for(int j=i;j<MAX;j+=i) 
        {
            // i is divisor of all j 
            if(nod[j].second == -1 || nod[j].second == 1)
            {
                if(nod[j].first % nod[i].first == 0)
                    nod[j].second = 1 ; 
                else 
                    nod[j].second = 0 ;
            }
        }
    }
    
}
int main()
{
    nofDivisors();
    int size=1;
    for(int x=1;x<MAX;x++)
    {        
        if((nod[x].first > 3) && (nod[x].second == 1))
        {
            arr[size++] = x;
        }        
    }
    for(int k=1 ; k<size ; k++)
    {
        if(k%108 == 0)
            printf("%d\n",arr[k]);
    }
    return 0;
}

