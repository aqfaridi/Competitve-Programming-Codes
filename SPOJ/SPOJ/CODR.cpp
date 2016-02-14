/**
 * SPOJ Problem Set (classical)
 * 13877. LOGIC
 * Problem code: CODR
 *
 * Mr.X  has recently graduated from his university.He was called for
 * an interview by a company Y.In the coding round the company asked
 * from Mr.X to decrypt a set of 3 digit numbers using some
 * algorithm.Mr.X does not have very good programming skills,but he
 * knows you as a friend and a talented programmer.Help Mr.X to get
 * selected for the job.
 * Input
 *
 * Each line of input consists of a 3 digit number. Inputs are
 * terminated when 0 is encounterred.
 * Output
 *
 * Ouput consists of a decrypted number for each input number.
 * Example
 *
 * Input:
 *
 * 999
 * 111
 * 124
 * 987
 * 0
 *
 *
 *  Output:
 *
 *  8181261
 *  010120
 *  0208100
 *  7256821
 *  */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n,unit,tens,hunds;
    int mult1,mult2,add1,add2;
    while(1)
    {

        ostringstream convert1,convert2,convert3,convert4;
        scanf("%d",&n);
        string str="";
        if(n==0)
            break;
        unit = (n%10);
        tens = (n/10)%10;
        hunds = (n/100)%10;
        mult1= tens*hunds;
        mult2= unit*tens;
        add1 = mult1%10 + mult2%10;
        add2 = mult1/10 + mult2/10;

        if(mult1%10 == mult1) //single digit
            {str +='0'; str+= ('0'+mult1);} //adding extra 0 and converting to char
        else
        {
            convert1 << mult1;            
            str += convert1.str();
        }
        if(mult2%10 == mult2)
            {str +='0'; str += ('0'+mult2);}
        else
        {
            convert2 << mult2;
            str += convert2.str();
        }
       
        if(add1%10 == add1) //single digit
            { str+= ('0' + add1);} //no need to add extra 0 and converting to char
        else
        {
            convert3 << add1;            
            str += convert3.str();
        }
        if(add2%10 == add2)
            {  str += ('0' + add2);}
        else
        {
            str += ('0' + add2%10);
            str += ('0' + add2/10);
        }

        cout<<str<<endl;
       



    }
    return 0;
}

