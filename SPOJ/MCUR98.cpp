#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MAX 1000000
int arr[MAX*10];
void selfno()
{
    int n,sod;
    for(int i=1;i<MAX;i++)
    {
        sod = 0;
        n = i;
        while(n)
        {
            sod += (n%10);
            n /= 10;
        }
        arr[sod + i] = 1;
        if(!arr[i])
            printf("%d\n",i);
    }
}
int main()
{
    selfno();
    return 0;
}


