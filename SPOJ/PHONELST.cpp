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

#define MAX 100010
#define MOD 1000000007    

namespace trie
{
    #define size 10
    char ch='0';
    struct node
    {
        int words;
        int prefixes;
        node* child[size];
    };

    node* init_root()
    {
        node* root = new node;
        for(int i=0;i<size;i++)
            root -> child[i] = NULL;
        root -> words = 0;
        root -> prefixes = 0;

        return root;
    }

    node* addNode()
    {
        node* temp = new node;
        for(int i=0;i<size;i++)
            temp -> child[i] = NULL;
        temp -> words = 0;
        temp -> prefixes = 0;    
        return temp;
    }
    
    void addWord(node* root,string str)
    {
        int l = str.length(),idx;
        node* curr = root;
        node* parent = root;

        for(int i=0;i<l;i++)
        {
            idx = str[i] - ch;
            parent = curr;
            curr = curr -> child[idx];
            if(curr == NULL)
                parent->child[idx] = addNode();
            curr = parent -> child[idx];
            curr ->prefixes++;
            if(i == l-1)
                curr -> words++;
        }
    }

    int findWord(node* root,string str)
    {
        node* curr = root;
        int idx,l = str.length();
        for(int i=0;i<l;i++)
        {
            idx = str[i]- ch;
            curr = curr -> child[idx];
            if(curr == NULL)
                return 0;
        }
        return curr->words;
    }

    int countPrefix(node* root,string prefix)
    {
        node* curr = root;
        int idx,l = prefix.length();
        for(int i=0;i<l;i++)
        {
            idx = prefix[i] - ch;
            curr = curr -> child[idx];
            if(curr == NULL)
                return 0;
        }
        return curr -> prefixes;
    }

    int chkWord(node* root,string prefix)
    {
        node* curr = root;
        node* parent = root;
        int idx,l = prefix.length();
        for(int i=0;i<l;i++)
        {
            idx = prefix[i] - ch;
            parent = curr;
            curr = curr -> child[idx];
            if(curr == NULL)
                return (parent -> words);
        }
        return curr -> prefixes;
    }
}
using namespace trie;
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    bool flag;
    string str;
    cin>>t;
    while(t--)
    {
        flag = true;      
        cin>>n;
        node* root = init_root(); 
        for(int i=0;i<n;i++)
        {
            cin>>str;
            if(chkWord(root,str))
                flag = false;
            addWord(root,str);
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
