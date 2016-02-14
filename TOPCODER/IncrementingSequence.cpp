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

class IncrementingSequence {
public:
    int mark[100];
	string canItBeDone(int, vector <int>);
};

string IncrementingSequence::canItBeDone(int k, vector <int> A) {
    int n = A.size(),i,j;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
            if((A[j] <= i && A[j] % k == i%k)  && mark[j] == 0)
            {
                mark[j] = 1;
                break;
            }
        if(j==n)
            return "IMPOSSIBLE";
    }

    return "POSSIBLE";
}


double test0() {
	int p0 = 2;
	int t1[] = {22, 13, 19, 7, 2, 16, 16, 1, 10, 6, 10, 24, 15, 21, 4, 18, 10, 3, 11, 5, 20, 25, 5, 13, 25};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IncrementingSequence * obj = new IncrementingSequence();
	clock_t start = clock();
	string my_answer = obj->canItBeDone(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "IMPOSSIBLE";
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
	int p0 = 5;
	int t1[] = {2,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IncrementingSequence * obj = new IncrementingSequence();
	clock_t start = clock();
	string my_answer = obj->canItBeDone(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "IMPOSSIBLE";
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
	int p0 = 1;
	int t1[] = {1,1,1,1,1,1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IncrementingSequence * obj = new IncrementingSequence();
	clock_t start = clock();
	string my_answer = obj->canItBeDone(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "POSSIBLE";
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
	int p0 = 2;
	int t1[] = {5,3,3,2,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IncrementingSequence * obj = new IncrementingSequence();
	clock_t start = clock();
	string my_answer = obj->canItBeDone(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "IMPOSSIBLE";
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
	int p0 = 9;
	int t1[] = {1,2,3,1,4,5,6,7,9,8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IncrementingSequence * obj = new IncrementingSequence();
	clock_t start = clock();
	string my_answer = obj->canItBeDone(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "POSSIBLE";
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
	int p0 = 2;
	int t1[] = {1,1,1,1,1,1,2,2,2,2,2,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IncrementingSequence * obj = new IncrementingSequence();
	clock_t start = clock();
	string my_answer = obj->canItBeDone(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "POSSIBLE";
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
	int p0 = 1;
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	IncrementingSequence * obj = new IncrementingSequence();
	clock_t start = clock();
	string my_answer = obj->canItBeDone(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "POSSIBLE";
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
