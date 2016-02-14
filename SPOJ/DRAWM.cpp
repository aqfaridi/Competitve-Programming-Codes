#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char arr[100][100];
int main()
{
    int t,n,next,prev,minn;
    int rows,checkprev,maxx;
    while(1)
    {
        cin>>n;
        checkprev = 0;
        rows = 50;
        minn = INT_MAX;
        maxx = -INT_MAX;
        if(n==-1)
            break;
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                arr[i][j] = ' ';
        cin>>prev;
        for(int i=0;i<n;i++)
        {
            cin>>next;
            if(next > prev)
            {
                if(checkprev==1) rows--;
                arr[rows][i] = '/';
                checkprev = 1;
            }
            else if(next == prev)
            {
                if(checkprev == 1) rows--;
                arr[rows][i] = '_';
                checkprev = 0;
            }
            else
            {
                if(checkprev != 1) rows++;
                arr[rows][i] = '\\';
                checkprev = -1;
            }
            prev = next;
            minn = min(minn,rows);
            maxx = max(maxx,rows);
        }
        /**
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<n;j++)
                cout<<arr[i][j];
            cout<<endl;
        }
        **/
        for(int i=minn;i<=maxx;i++)
        {
            for(int j=0;j<=n;j++)
                cout<<arr[i][j];
            cout<<endl;
        }
        cout<<"***"<<endl; 
    }
    return 0;
}


