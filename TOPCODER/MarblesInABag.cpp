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

class MarblesInABag {
public:
    double **mem;
	double getProbability(int, int);
    double solve(int,int);
};

double MarblesInABag::getProbability(int redCount, int blueCount) {

    try
    {

        mem = new double*[redCount+10];
        for(int i=0;i<redCount+10;i++)
            mem[i] = new double[blueCount+10];
    
    }
    catch(std::bad_alloc& e)
    {
        return 0.0;
    }
    for(int i=0;i<=redCount;i++)
        for(int j=0;j<=blueCount;j++)
            mem[i][j] = -1.0;
    return solve(redCount,blueCount);
}

double MarblesInABag::solve(int r,int b)
{
    //base case
    if(r == 0 && b != 0)    return 1.0;
    if(r != 0 && b == 0)    return 0.0;
    if(r == 0 && b == 0)    return 1.0;

    double& res = mem[r][b];
    if(res != -1)   return mem[r][b];
    res = 0.0;

    res = (r/((b+r)*1.0)) * solve(r-1,b-1) + (b/((b+r)*1.0)) * solve(r,b-2);

    return res;
}

double test0() {
	int p0 = 1;
	int p1 = 2;
	MarblesInABag * obj = new MarblesInABag();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.3333333333333333;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 2;
	int p1 = 3;
	MarblesInABag * obj = new MarblesInABag();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.13333333333333333;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 2;
	int p1 = 5;
	MarblesInABag * obj = new MarblesInABag();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.22857142857142856;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 11;
	int p1 = 6;
	MarblesInABag * obj = new MarblesInABag();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 4;
	int p1 = 11;
	MarblesInABag * obj = new MarblesInABag();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.12183372183372182;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
