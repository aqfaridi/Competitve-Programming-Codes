/**
 * SPOJ Problem Set (classical)
 * 7406. Beehive Numbers
 * Problem code: BEENUMS
 *
 * A beehive is an enclosed structure in which some honey bee species
 * live and raise their
 * young. In this problem we consider a two-dimensional sketch of the
 * beehives. Each
 * beehive is composed of a certain number of cells, where each cell
 * is a regular hexagon.
 * Each cell may have some neighbors, which are other cells that share
 * a side with that cell.
 * A cell with exactly 6 neighbors is an internal cell, while a cell
 * with fewer neighbors is an
 * external one. Notice that an external cell can always be changed to
 * internal by adding
 * some neighbor cells.
 *
 *
 * We are interested in a particular class of beehives. This class of
 * valid beehives is defined
 * recursively as follows: a) a single cell is a valid beehive; and b)
 * given a valid beehive B,
 * if we add the minimum number of cells such that each external cell
 * of B becomes an
 * internal cell, the result is a valid beehive.
 *
 * The number of cells in a valid beehive is called a beehive number.
 * Given an integer N ,
 * you must decide whether it is a beehive number.
 * Input
 *
 * Each test case is described using a single line. The line contains
 * an integer N (1 . N .
 * 109 ). The end of input is indicated with a line containing a
 * single .1.
 * Output
 *
 * For each test case, output a single line containing an uppercase
 * .Y. if N is a beehive
 * number, or an uppercase .N. otherwise.
 * Example
 *
 * Input:
 * 43
 * 1
 * 7
 * 19
 * 15
 * -1
 *  Output:
 *  N
 *  Y
 *  Y
 *  Y
 *  N
 *  */
#include<iostream>
#include <cstdio>
using namespace std;
int main(){
        long long int j,k;
        int t;

        while(scanf("%lld",&j))
        {
            if(j==-1){break;}
            t=1;
            k=1;
            for(int i=0;i<100000;i++)
            {
                                                                                                                                                          k=k+6*i;
                                                                                                                                                          if(k==j){
                                                                                                                                                              t=0;
                                                                                                                                                              cout<<"Y"<<endl;
                                                                                                                                                                                                                                                                                                                                                                                                                                                     break;}
                                                                                                                                                                                                                                                                                                     if(k>j)                                                                                                                                                                                                                                                                                     break;  
            }

                                                                                                                                                                                                                                                                                                                                                                                                                                             if(t!=0){cout<<"N"<<endl;}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            }
            return 0;
}



