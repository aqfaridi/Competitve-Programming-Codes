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

class ConsecutiveNumbers {
public:
	vector <int> missingNumber(vector <int>);
};

vector <int> ConsecutiveNumbers::missingNumber(vector <int> numbers) {

    vector<int> v;
    int n = numbers.size(),cnt=0,temp;
    sort(numbers.begin(),numbers.end());
    bool flag = false;
    for(int i=1;i<n;i++)
    {
        if(numbers[i]-numbers[i-1] != 1)
        {
            cnt++;
            temp = numbers[i-1];
        }

        if((numbers[i] - numbers[i-1] >= 3) || (numbers[i]-numbers[i-1] <= 0))
             flag = true;
    }

    if(cnt > 1 || flag)
        return v;

    if(!cnt) {
        if(numbers[0] - 1 >= 1)
            v.push_back(numbers[0]-1);
        v.push_back(numbers[n-1] + 1);
    }
    else
        v.push_back(temp+1);
    return v;
}


double test0() {
	int t0[] = {98773594, 98773608, 98773604, 98773602, 98773610, 98773598, 98773603, 98773600, 98773606, 98773601, 98773607, 98773599, 98773597, 98773605, 98773596, 98773609, 98773611, 98773595, 98773613};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConsecutiveNumbers * obj = new ConsecutiveNumbers();
	clock_t start = clock();
	vector <int> my_answer = obj->missingNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {98773612 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {3,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConsecutiveNumbers * obj = new ConsecutiveNumbers();
	clock_t start = clock();
	vector <int> my_answer = obj->missingNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {5,6,7,8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConsecutiveNumbers * obj = new ConsecutiveNumbers();
	clock_t start = clock();
	vector <int> my_answer = obj->missingNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {4, 9 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {1000000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConsecutiveNumbers * obj = new ConsecutiveNumbers();
	clock_t start = clock();
	vector <int> my_answer = obj->missingNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {999999999, 1000000001 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {1,6,9,3,8,12,7,4,11,5,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConsecutiveNumbers * obj = new ConsecutiveNumbers();
	clock_t start = clock();
	vector <int> my_answer = obj->missingNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {2 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConsecutiveNumbers * obj = new ConsecutiveNumbers();
	clock_t start = clock();
	vector <int> my_answer = obj->missingNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {2 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
