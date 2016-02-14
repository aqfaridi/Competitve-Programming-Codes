#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,count,count1;
    string subseq,str;
    scanf("%d",&t);
    while(t--)
    {
        int j=0;
        count=0;
        count1=0;
        cin>>subseq>>str;
        //cout<<subseq<<str;
        for(int i=0;subseq[i];i++)
        {
            for(;str[j];j++)
            {
                //cout<<"hi"<<i<<j;
                //cout<<subseq[i]<<str[j]<<endl;
                if(subseq[i]==str[j])
                { count++;j++; break;}
            }

        }
        j=0;
        for(int i=0;str[i];i++)
        {
            for(;subseq[j];j++)
            {
                if(str[i]==subseq[j])
                {count1++;j++;break;}
            }
        }
        //cout<<count;
        if(count==subseq.length() or count1==str.length())
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}

