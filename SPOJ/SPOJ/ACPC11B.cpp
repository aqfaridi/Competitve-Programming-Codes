/**
 * SPOJ Problem Set (classical)
 * 10239. Between the Mountains
 * Problem code: ACPC11B
 *
 *  
 *  Did you try to ride a telepherique (cable car)? It is a lot of
 *  fun. Our company is trying to
 *  build a new telepherique line between two high mountains and you
 *  will be invited for a free
 *  ride. The trick to get your free ride is to help the company in
 *  building the telepherique line.
 *  The company wants to build two platforms, one on each mountain.
 *  The line will extend
 *  between these two platforms. The suitable points for holding a
 *  platform in each mountain
 *  were determined, and the altitudes of these points were reported.
 *  One of the talented engineers suggested that the company can save
 *  a lot of energy if the two
 *  stations have the same altitude or at least have altitudes which
 *  are as close to each other as
 *  possible. Your job is to select two points, one at each mountain,
 *  from those suitable points,
 *  so that the altitude difference between the two points is as
 *  little as possible.
 *  Input
 *  Your program will be tested on one or more test cases. The first
 *  line of the input will be a
 *  single integer T , the number of test cases (1 . T . 100). Follows
 *  2T lines containing the
 *  test cases, each on a pair of lines.
 *  Each of the two lines in a case describe the altitudes of suitable
 *  points to build a platform
 *  on one mountain. Each line starts with an integer N , the number
 *  of reported altitudes
 *  (1 . N . 1, 000), followed by N integers, which represent the
 *  altitudes reported from this
 *  mountain. Any altitude value will be between 1 and 1, 000, 000,
 *  inclusive.
 *  Output
 *  For each test case, output, on a single line, a single number
 *  representing the minimum
 *  altitude difference between two suitable platform points, one at
 *  each mountain.
 *
 *  Did you try to ride a telepherique (cable car)? It is a lot of
 *  fun. Our company is trying to build a new telepherique line
 *  between two high mountains and you will be invited for a free
 *  ride. The trick to get your free ride is to help the company in
 *  building the telepherique line.
 *
 *  The company wants to build two platforms, one on each mountain.
 *  The line will extend between these two platforms. The suitable
 *  points for holding a platform in each mountain were determined,
 *  and the altitudes of these points were reported.
 *
 *  One of the talented engineers suggested that the company can save
 *  a lot of energy if the two stations have the same altitude or at
 *  least have altitudes which are as close to each other as possible.
 *  Your job is to select two points, one at each mountain, from those
 *  suitable points, so that the altitude difference between the two
 *  points is as little as possible.
 *
 *  Input
 *
 *  Your program will be tested on one or more test cases. The first
 *  line of the input will be a single integer T , the number of test
 *  cases (1 . T . 100). Follows 2T lines containing the test cases,
 *  each on a pair of lines.
 *
 *  Each of the two lines in a case describe the altitudes of suitable
*  points to build a platform on one mountain. Each line starts with
*  an integer N , the number of reported altitudes (1 . N . 1,000),
    *  followed by N integers, which represent the altitudes reported
    *  from this mountain. Any altitude value will be between 1 and
    *  1,000,000, inclusive.
    *
    *  Output
    *
    *  For each test case, output, on a single line, a single number
    *  representing the minimum
    *
    *  altitude difference between two suitable platform points, one
    *  at each mountain.
    *
    *   
    *
    *   Example
    *
    *    
    *
    *    Input:
    *    2
    *    8 1 3 5 7 9 7 3 1
    *    8 2 4 6 8 10 8 6 2
    *    8 2 3 5 10 9 3 2 1
    *    7 1 2 6 12 13 3 2
    *
    *    Output:
    *    1
    *    0
    *    */
    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <algorithm>
    using namespace std;
    int main()
    {
        int t,n1,n2,min;
        int m1[1001],m2[1001];
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&n1);
            for(int i=0;i<n1;i++)
            {
                scanf("%d",&m1[i]);
            }
            scanf("%d",&n2);
            for(int i=0;i<n2;i++)
            {
                scanf("%d",&m2[i]);
            }
            sort(m1,m1+n1);
            sort(m2,m2+n2);

            min=abs(m1[0]-m2[0]);
            for(int i=0;i<n1;i++)
            {
                for(int j=0;j<n2;j++)
                {
                    if(abs(m1[i]-m2[j]) <  min)
                    {
                        min=abs(m1[i]-m2[j]);
                    }
                }
            }
            /*
            cout<<endl;
            for(int i=0;i<n1;i++)
            {
                cout<<near[i]<<" ";
            }
            */
           
        

            printf("%d\n",min);
          

        }
        return 0;
    }
    
