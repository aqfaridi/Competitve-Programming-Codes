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
int A[10010],B[10010];
int main()
{
    int n,k,ta,tb,i=0;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];

    if(A[0]>k && B[0] >k)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
   
    for(i=1;i<n;i++)
    {
        ta = A[i]; tb = B[i];
        A[i] += A[i-1];
        B[i] += B[i-1];

        if(A[i] + tb < B[i])
            B[i] = A[i] + tb;
        else if(B[i] + ta < A[i])
            A[i] = B[i] + ta;

        if(A[i]>k && B[i]>k)
            break;
    }

    cout << i << " " << min(A[i-1],B[i-1])<<endl;
    return 0;
}
