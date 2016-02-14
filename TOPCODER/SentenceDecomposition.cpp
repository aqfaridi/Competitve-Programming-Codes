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

class SentenceDecomposition {
public:
    string str;
    vector<string> words;
    int mem[100],n,len;
	int decompose(string, vector <string>);
    int solve(int);
    int match(string,string);
};

int SentenceDecomposition::decompose(string sentence, vector <string> validWords) {

    n = validWords.size();
    str = sentence;
    len = str.length();
    words = validWords;
    memset(mem,-1,sizeof(mem));
    int ret = solve(0);

    if(ret == (1<<20))   return -1;
    return ret;
}
int SentenceDecomposition::solve(int idx)
{
    //base case
    if(idx == len)  return 0;

    int& res = mem[idx];
    if(res != -1 ) return res;
    res = (1<<20);
    
    for(int i=0;i<n;i++)
    {
        int l = words[i].length();
        if(min(l,len-idx) != l) continue;
        int diff = match(str.substr(idx,l) , words[i]);
        if(diff == -1)  continue;
        res = min(res,diff + solve(idx+l));
    }
    return res;
}

int SentenceDecomposition::match(string s,string word)
{
    string t1 = s,t2 = word;
    sort(t1.begin(),t1.end());
    sort(t2.begin(),t2.end());
    if(t1 != t2)    return -1;

    int diff = 0;
    for(int i=0;i<s.length();i++)
        if(s[i] != word[i])
            diff++;
    
    return diff;
}

double test0() {
	string p0 = "neotowheret";
	string t1[] = {"one", "two", "three", "there"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
	string p0 = "abba";
	string t1[] = {"ab", "ac", "ad"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string p0 = "thisismeaningless";
	string t1[] = {"this", "is", "meaningful"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	string p0 = "ommwreehisymkiml";
	string t1[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	string p0 = "ogodtsneeencs";
	string t1[] = {"go", "good", "do", "sentences", "tense", "scen"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
double test5() {
	string p0 = "sepawaterords";
	string t1[] = {"separate","words"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SentenceDecomposition * obj = new SentenceDecomposition();
	clock_t start = clock();
	int my_answer = obj->decompose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
