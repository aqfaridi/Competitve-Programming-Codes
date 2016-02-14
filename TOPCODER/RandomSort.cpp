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

class RandomSort {
public:
    map<vector<int>,double> mem;
    double getExpected(vector <int>);
    double solve(vector<int>);
};

double RandomSort::getExpected(vector <int> permutation) {
	return solve(permutation);
}

double RandomSort::solve(vector<int> perm)
{
    int swaps = 0;
    double& res = mem[perm];
    if(res != 0)  return res;
    res = 0.0;
    for(int i=0;i<perm.size();i++)
        for(int j=i+1;j<perm.size();j++)
            if(perm[i] > perm[j])
            {
                swap(perm[i],perm[j]);
                res += (1 + solve(perm));
                swaps++;
                swap(perm[i],perm[j]);
            }

    if(swaps == 0)
        return 0.0;
    else
        return res/=swaps;
}


double test0() {
	int t0[] = {1,3,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RandomSort * obj = new RandomSort();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {4,3,2,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RandomSort * obj = new RandomSort();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 4.066666666666666;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RandomSort * obj = new RandomSort();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {2,5,1,6,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	RandomSort * obj = new RandomSort();
	clock_t start = clock();
	double my_answer = obj->getExpected(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 5.666666666666666;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
