#include <iostream>
using namespace std;
long long f[40],g[40],h[40],l[40],m[40];
int main()
{
    f[0]=g[1]=h[1]=l[1]=m[1]=1;
    f[1]=g[0]=h[0]=l[0]=m[0]=0;
    for(int i=2;i<=34;i++)
    {
        f[i] = f[i-2]+2*g[i-1]+2*h[i-1]+2*l[i-1]+m[i-1];   
        g[i] = f[i-1]+g[i-2];
        h[i] = f[i-1]+h[i-2];
        l[i] = f[i-1]+l[i-2]+g[i-1];
        m[i] = f[i-1]+m[i-2]+l[i-1];
    }

    for(int i=2;i<=34;i+=2)
        cout<<f[i]<<endl;
    return 0; 
}
