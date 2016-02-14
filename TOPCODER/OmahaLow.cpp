#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cmath>
#include <map>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long LL;

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

class OmahaLow {
public:
	string low(string, string);
};

string OmahaLow::low(string sc, string pc) {
    
    string ans = "ZZZZZ";
    for(int i=0;i<5;i++)
        for(int j=i+1;j<5;j++)
            for(int k=j+1;k<5;k++)
                for(int x = 0;x<4;x++)
                    for(int y=x+1;y<4;y++)
                    {
                        string hand="";
                        hand += sc[i];hand  += sc[j];hand += sc[k];
                        hand += pc[x];hand += pc[y];
                        sort(hand.begin(),hand.end());
                        //check validity of hand
                        for(int z=0;z<4;z++)
                            if(hand[z] == hand[z+1] || hand[z] > '8' || hand[z+1] > '8')
                                goto down;
                            
                    
                        for(int z = 0;z < 5;z++)
                            if(hand[z] < ans[z]){
                                ans = hand;
                                break;
                            }

                        down:;

                    }

    if(ans == "ZZZZZ")
        return "";
    else{
        reverse(ans.begin(),ans.end());
        return ans;
    }

}


double test0() {
	string p0 = "123QK";
	string p1 = "45TJ";
	OmahaLow * obj = new OmahaLow();
	clock_t start = clock();
	string my_answer = obj->low(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "54321";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "55443";
	string p1 = "2345";
	OmahaLow * obj = new OmahaLow();
	clock_t start = clock();
	string my_answer = obj->low(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "1357Q";
	string p1 = "345J";
	OmahaLow * obj = new OmahaLow();
	clock_t start = clock();
	string my_answer = obj->low(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "75431";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "76285";
	string p1 = "4816";
	OmahaLow * obj = new OmahaLow();
	clock_t start = clock();
	string my_answer = obj->low(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "65421";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "12345";
	string p1 = "3339";
	OmahaLow * obj = new OmahaLow();
	clock_t start = clock();
	string my_answer = obj->low(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string p0 = "58463";
	string p1 = "947K";
	OmahaLow * obj = new OmahaLow();
	clock_t start = clock();
	string my_answer = obj->low(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "76543";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	string p0 = "67521";
	string p1 = "J859";
	OmahaLow * obj = new OmahaLow();
	clock_t start = clock();
	string my_answer = obj->low(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "86521";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
