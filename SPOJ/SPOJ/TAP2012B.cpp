#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#define MAX 10010

using namespace std;

typedef pair<int,int> my_pair;
int main()
{
    long long count;
    int i,n,index,b[MAX],c[MAX],k;
    vector< my_pair > v;
    vector<int> srch;
    while(1)
    {
        v.clear();
        scanf("%d",&n);
        if(n==-1)
            break;
        count = 0LL; 
        k=0;
        

        for(i=sqrt(n);i>=1;i--)
        {
            for(int j=0;(j<=i);j++)
            {
                // b and c combination                
                b[k++] = (n-i*j)/(i+j); //(b*c) , b
              
            }
        }
        for(i=0;i<k;i++)
            cout<<b[i]<<" ";
        cout<<endl;

        /**
        sort(v.begin(),v.end());
        for(i=0;i<v.size();i++)
            cout<<v[i].first<<" "<<v[i].second<<endl;
        
        vector<my_pair>::iterator it;
        for(int i=1;i<=n;i++)
        {
            it = lower_bound(v.begin(),v.end(),i);
            index = it - v.begin();
            if((v[index].first == i) && (v[index].second <= i))
            {
              count++;  
            }

        }
**/
        //sort(b,b+k);
       // for(int i=0;i<k;i++)
         //   cout<<b[k]<<" ";
        cout<<endl;

       // for(int i=1;i<=n;i++)
        //{
         //   if(binary_search(b,b+k,i))
           //     count++;
           // count += upper_bound(b,b+k,i)-lower_bound(b,b+k,i);
           

        //}
        
        /**
        bool b;
        count = 0LL ;
        for(int i=n;i>=1;i--)
        {
            for(int j=1;(j<=i && j<=100);j++)
            {
                
                for(int k=0;(k<=j && k<=100);k++)
                {                   
                    if(i*(j+k) + (j*k) == n)
                    {   
                        cout <<i<<","<<j<<","<<k<<endl;
                        count++;
                        //break;
                    }
                }
                //if(b)
                  //  break;
            }

        }
        **/
        cout<<count<<endl;
    }
    return 0;
}

