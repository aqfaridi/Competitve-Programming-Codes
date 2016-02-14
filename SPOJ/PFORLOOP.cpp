#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string str,s;
vector<int> v;
vector< int > store;

int main()
{
        int num;
        //freopen("input.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
        while(getline(cin,str))
        {
                stringstream mystr(str);
                while(mystr >> s)
                {
                        //cout<<s<<" ";
                        stringstream(s) >> num;
                        v.push_back(num);
                }
        }

        sort(v.begin(),v.end());

        int d;

        store.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        {
                d = v[i] - v[i-1];
                if(d==1)
                        continue;
                else
                {
                        store.push_back(v[i-1]);
                        store.push_back(v[i]);
                }
        }       //cout<<v[i]<<" ";

        store.push_back(v[v.size()-1]);

        for(int i=0;i<store.size();i++)
        {
                //pair i and i+1
                cout<<"for (int i = "<<store[i]<<"; i <= "<<store[i+1]<<"; i++) cout << i << \" \";";
                cout<<endl;
                i++;
        }

        return 0;

}

