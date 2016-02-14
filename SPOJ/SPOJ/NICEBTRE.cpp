/**
 * SPOJ Problem Set (classical)
 * 13384. Nice Binary Trees
 * Problem code: NICEBTRE
 *
 *  
 *  For example, the following tree is nice,
 *  <nice-tree.jpg>
 *  but the following tree is not.
 *  <not-nice-tree.jpg>
 *  The leaves of a nice binary tree are labeled by the letter .l.,
 *  and other nodes are labeled by the letter .n..
 *  Given the pre-order traversal of a nice binary tree, you are
 *  required to find the depth of the tree.
 *  Notes : 
 *  1. The depth of a tree is defined as the length of the longest
 *  path with one end at the root.
 *  2. The pre-order traversal of the tree in the first image above
 *  produces the string .nlnnlll..
 *
 *  Binary trees can sometimes be very difficult to work with.
 *  Fortunately, there is a class of trees with some really nice
 *  properties. A rooted binary tree is called .nice., if every node
 *  is either a leaf, or has exactly two children.
 *
 *  For example, the following tree is nice,
 *
 *  nice tree
 *
 *  but the following tree is not.
 *
 *  not a nice binary tree
 *
 *  The leaves of a nice binary tree are labeled by the letter .l.,
 *  and other nodes are labeled by the letter .n..
 *
 *  Given the pre-order traversal of a nice binary tree, you are
 *  required to find the depth of the tree.
 *
 *  Notes : 
 *
 *  1. The depth of a tree is defined as the length of the longest
 *  path with one end at the root.
 *
 *  2. The pre-order traversal of the tree in the first image above
 *  produces the string .nlnnlll..
 *
 *   
 *   Input
 *
 *   The first line contains the number of test cases T. T lines
 *   follow. Each line contains a string, which represents the
 *   pre-order traversal of a .nice. binary tree. Leaves are
 *   represented by the letter .l. and other nodes by the letter .n..
 *   The input is guaranteed to be the preorder traversal of a nice
 *   binary tree.
 *
 *    
 *    Output
 *
 *    Output one line for each test case, containing a single integer,
 *    the depth of tree.
 *
 *     
 *     Constraints
 *
 *     0 < T < 20
 *
 *     Length of the input string in each test case is at most 10000.
 *
 *      
*      Example
*
*      Input:
*      3
*      l
*      nlnll
*      nlnnlll
*
*
*      Output:
*      0
*      2
*      3
*      */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char str[10010];
struct treenode
{
    char data;
    struct treenode* left;
    struct treenode* right;
};
void preorder_traversal(struct treenode* root)
{
    if(root!=NULL)
    {
        printf("%c ",root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    

}
int maxheight(struct treenode* root)
{
    int ht_left,ht_right;
    if(root==NULL) //base case
        return 0;
    ht_left=maxheight(root->left);
    ht_right=maxheight(root->right);
    if(ht_left > ht_right)
        return 1 + ht_left;
    else
        return 1 + ht_right;
}
int i;
struct treenode*  maketree()
{
    struct treenode* root=NULL;
    if(str[i]=='n')
    {
        root=new treenode;//like int* ptr= new int;
        //preorder****************
        root->data=str[i++];
        root->left=maketree();
        root->right=maketree();
    }
    else if(str[i]=='l')
    {
        root=new treenode;
        root->data=str[i++];
        root->left=NULL;
        root->right=NULL;       
    }
    return root;   
}
int main()
{
    int t,max;
    struct treenode* root;
    scanf("%d",&t);
    while(t--)
    {
        i=0;
        root=NULL;
        scanf("%s",str);
        root=maketree();
        //preorder_traversal(root);
        max=maxheight(root);
        printf("%d\n",max-1);
    }

    return 0;
}

