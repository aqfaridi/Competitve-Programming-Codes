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

class DreamingAboutCarrots {
public:
	int carrotsBetweenCarrots(int, int, int, int);
};

int DreamingAboutCarrots::carrotsBetweenCarrots(int x1, int y1, int x2, int y2) {
    int Nr = (y2-y1),Dr = (x2-x1),cnt = 0;
    int start_row = min(x1,x2),end_row = max(x1,x2);
    int start_col = min(y1,y2),end_col = max(y1,y2);
    for(int x=start_row;x<=end_row;x++) 
        for(int y=start_col;y<=end_col;y++) 
            if(Nr*(x-x1) == Dr*(y-y1))
                cnt++;
    return cnt-2;
}


double test0() {
	int p0 = 1;
	int p1 = 1;
	int p2 = 5;
	int p3 = 5;
	DreamingAboutCarrots * obj = new DreamingAboutCarrots();
	clock_t start = clock();
	int my_answer = obj->carrotsBetweenCarrots(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 0;
	int p1 = 0;
	int p2 = 1;
	int p3 = 1;
	DreamingAboutCarrots * obj = new DreamingAboutCarrots();
	clock_t start = clock();
	int my_answer = obj->carrotsBetweenCarrots(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 50;
	int p1 = 48;
	int p2 = 0;
	int p3 = 0;
	DreamingAboutCarrots * obj = new DreamingAboutCarrots();
	clock_t start = clock();
	int my_answer = obj->carrotsBetweenCarrots(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 0;
	int p1 = 0;
	int p2 = 42;
	int p3 = 36;
	DreamingAboutCarrots * obj = new DreamingAboutCarrots();
	clock_t start = clock();
	int my_answer = obj->carrotsBetweenCarrots(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
