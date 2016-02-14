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

class CatsOnTheLineDiv2 {
public:
	string getAnswer(vector <int>, vector <int>, int);
};

string CatsOnTheLineDiv2::getAnswer(vector <int> position, vector <int> count, int time) {
    int n = position.size();
    count.resize(10001);
    for(int i=0;i<n;i++){
        position[i] += 5000;
        count[position[i]] = count[i];
        count[i] = 0;
    }
    
    for(int i=1;i<=time;i++)
    {
       for(int j=1;j<=10000;j++)
       {
           if(count[j] >= 2){
                count[j]-=2;
                count[j-1]++;
                count[j+1]++;
            }            
       }
    }

    for(int i=5000;i<5020;i++)
        cout<<count[i]<<" ";
    cout<<endl; 

    for(int i=1;i<=10000;i++)
        if(count[i] >= 2)
            return "Impossible";

    return "Possible";
}


double test0() {
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	CatsOnTheLineDiv2 * obj = new CatsOnTheLineDiv2();
	clock_t start = clock();
	string my_answer = obj->getAnswer(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	CatsOnTheLineDiv2 * obj = new CatsOnTheLineDiv2();
	clock_t start = clock();
	string my_answer = obj->getAnswer(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {0, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	CatsOnTheLineDiv2 * obj = new CatsOnTheLineDiv2();
	clock_t start = clock();
	string my_answer = obj->getAnswer(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {5, 0, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 3, 5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	CatsOnTheLineDiv2 * obj = new CatsOnTheLineDiv2();
	clock_t start = clock();
	string my_answer = obj->getAnswer(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {5, 1, -10, 7, 12, 2, 10, 20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3, 4, 2, 7, 1, 4, 3, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 6;
	CatsOnTheLineDiv2 * obj = new CatsOnTheLineDiv2();
	clock_t start = clock();
	string my_answer = obj->getAnswer(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
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
