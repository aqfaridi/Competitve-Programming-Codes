#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t,a;
    float n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        n= 360.0/(180.0-a);
        //cout<<n<<endl;
        //cout<<(int)n<<endl;
        if( n == (int)n)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
