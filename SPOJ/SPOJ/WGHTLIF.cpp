#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;
void divisible(char tw[],long long sw)
{
    //cout<<tw;
    //ostringstream convert;
    
    unsigned long long  r=0,n,k=0;
    char Nr[110];
    for(int i=0;tw[i];i++)
    {
        r = r*10 + (tw[i]-'0');       
        n = r/sw;
        r %= sw;    
        //cout<<r<<endl;
        Nr[k++] = (n+'0');
        //cout<<Nr[k-1]<<endl;
        //convert<<n;
    }

    //Nr[k++]='\0';
    //Nr = convert.str();
    printf("%llu ",r);
   // for(int i=0;i<k;i++)
   //    cout<<Nr[i]<<" ";

    //cout<<endl;
    if(Nr[0]!='0')
        cout<<Nr[0];
    for(int i=1;i<k;i++)
    {
        if(Nr[0]=='0' && i==1)
        {
            while(Nr[i]==Nr[i-1])
                i++;
        }
       cout<<Nr[i];

    }
    
    printf("\n");
    
}
int main()
{
    int d;
    long long sw;
    char tw[110];
    scanf("%d",&d);
    while(d--)
    {
    //cin>>d>>tw>>sw;
        scanf("%s",tw);
        //cout<<tw;
        scanf("%lld",&sw);
        if(tw[0]=='0')
        {
            //cout<<"aqf"<<endl;
            printf("0 0\n");
            continue;
        }
        else if(sw==0)
        {
            printf("0 0\n");
            continue;
        }
    //cout<<tw<<" "<<sw<<endl;
        else
            divisible(tw,sw);
    }
    return 0;
}

