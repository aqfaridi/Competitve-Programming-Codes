"""
SPOJ Problem Set (classical)
10334. SOLDIERS
Problem code: SOLDIERS

Soldiers

Problem Statement:

How many maximum number of soldiers(chess) can be placed in a mxn
board so that none of them attack the other.

Input Specification:

The first line is an integer t, denoting the number of test cases.
Each test case is a single line with two integers m and n the number
of rows and columns in the board.

Output Specification:

For each test case print the maximum number of soldiers that can be
placed in a separate line.

Input Constraints:

1<=t<=100

1<=m<=10^30

1<=n<=10^30


Sample Input:

4

10 10

3 3

5 5

3 6

 

Sample Output:

50

6

15

12
"""
import math
 
t=int(raw_input())
while(t>0):
    try:
        s=raw_input()
        
        str=s.split(" ")  
        
        m=int(str[0])
        n=int(str[1])        
        
        a=int(math.ceil(m/2.0)) * n
        b=int(math.ceil(n/2.0)) * m
        
        if(a>b):
            print a
        else:
            print b
                    
            
        t=t-1
    except:
        break



