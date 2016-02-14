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
typedef pair<int,int> pii;
typedef pair < pii , pii > tri;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

class BubbleSortWithReversals {
public:
    int temp[60];
    int mark[60];
	int getMinSwaps(vector <int>, int);
};

int BubbleSortWithReversals::getMinSwaps(vector <int> arr, int kk) {

    vector< tri > v;
    memset(mark,0,sizeof(mark));
    int n = arr.size(),ptr,cnt;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            ptr = cnt = 0;
            for(int k=i;k<=j;k++)
                temp[ptr++] = arr[k];

            for(int k=0;k<ptr;k++)
                for(int l=0;l<ptr;l++)
                    if(temp[l] > temp[l+1])
                    {
                        swap(temp[l],temp[l+1]);
                        cnt++;
                    }
            v.push_back(make_pair(make_pair((j-i+1),cnt),make_pair(i,j)));
        }
    sort(v.begin(),v.end());

    int size = v.size(),kitne=0,lpos,rpos;
    for(int i=0;i<n;i++)
    {
        lpos = v[i].second.first;
        rpos = v[i].second.second;
        trace2(v[i].first.first,v[i].first.second);
        trace2(lpos,rpos);
        if((kitne < kk) && (!mark[lpos] && !mark[rpos]))
        {
            trace3(kitne,lpos,rpos);
            for(int j=lpos;j<=rpos;j++)
                mark[j] = 1;
            reverse(arr.begin() + lpos , arr.begin()+rpos+1);
            kitne++;
        }
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                ans++;
            }
    
    return ans;


}


double test0() {
	int t0[] = {6,8,8,7,7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	BubbleSortWithReversals * obj = new BubbleSortWithReversals();
	clock_t start = clock();
	int my_answer = obj->getMinSwaps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	int t0[] = {7,2,2,13,5,5,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	BubbleSortWithReversals * obj = new BubbleSortWithReversals();
	clock_t start = clock();
	int my_answer = obj->getMinSwaps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {12,5,1,10,12,6,6,10,6,8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	BubbleSortWithReversals * obj = new BubbleSortWithReversals();
	clock_t start = clock();
	int my_answer = obj->getMinSwaps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 12;
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
	int t0[] = {2,3,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	BubbleSortWithReversals * obj = new BubbleSortWithReversals();
	clock_t start = clock();
	int my_answer = obj->getMinSwaps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	int t0[] = {482,619,619,601,660,660,691,691,77,77,96,77};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 9;
	BubbleSortWithReversals * obj = new BubbleSortWithReversals();
	clock_t start = clock();
	int my_answer = obj->getMinSwaps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 22;
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
