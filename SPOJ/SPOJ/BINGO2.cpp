#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
    int num,arr[5][5];
    ios::sync_with_stdio(false);
    cout<<left<<setw(3)<<"B"<<left<<setw(3)<<"I"<<left<<setw(3)<<"N"<<left<<setw(3)<<"G"<<left<<setw(3)<<"O"<<endl;
    //srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        up:
        num = rand()%10 + 1; 
     
        for(int j=0;j<i;j++)
        {
            if(num==arr[0][j])
                goto up;
        }
        arr[0][i] = num;
    }
     
    for(int i=0;i<5;i++)
    {
        up1:
        num = rand()%10 + 11; 
     
        for(int j=0;j<i;j++)
        {
            if(num==arr[1][j])
                goto up1;
        }
        arr[1][i] = num;
    }
    for(int i=0;i<5;i++)
    {
        up2:
        num = rand()%10 + 21; 
     
        for(int j=0;j<i;j++)
        {
            if(num==arr[2][j])
                goto up2;
        }
        arr[2][i] = num;
    }
    for(int i=0;i<5;i++)
    {
        up3:
        num = rand()%10 + 31; 
     
        for(int j=0;j<i;j++)
        {
            if(num==arr[3][j])
                goto up3;
        }
        arr[3][i] = num;
    }
    for(int i=0;i<5;i++)
    {
        up4:
        num = rand()%10 + 41; 
     
        for(int j=0;j<i;j++)
        {
            if(num==arr[4][j])
                goto up4;
        }
        arr[4][i] = num;
    }
    /*****display*****/
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<left<<setw(3)<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}

