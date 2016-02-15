#include <bits/stdc++.h>

using namespace std;


vector<int> findPath(vector< vector<int> > arr)
{
	int N=arr.size(),M=arr[0].size();

	//first num, second: position,(x,y)
	vector< pair<int, pair<int,int> > > nums; 


	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++){
			if ((i==0 && j==0) || (i==N-1 && j==M-1))
				continue;
			nums.push_back({arr[i][j],{i,j}});
		}

	sort(nums.begin(),nums.end());

	//first: diagonal's number, second: position,(x,y)
	set< pair<int, pair<int,int> > > st;

	//up-left
	st.insert( {0,{0,0}});

	//bottom-right
	st.insert({M+N-2,{N-1,M-1}});

	//M+N-1 is number of all secondary diagonals
	for (int i=0;i<nums.size() && st.size()<(M+N-1);i++){
		int x=nums[i].second.first;
		int y=nums[i].second.second;
		int d=x+y;// current item diganol's number

		auto it=st.lower_bound({d,{0,0}});

		if (it->first == d) continue;
		int x1=(it->second).first;
		int y1=(it->second).second;
		if (x>x1 || y>y1) continue;

		it--;
		x1=(it->second).first;
		y1=(it->second).second;
		if (x<x1 || y<y1) continue;

		st.insert({d,{x,y}});
	}

	vector<int> path;
	for (auto it=st.begin();it!=st.end();it++){
		int x = (it->second).first;
		int y=(it->second).second;

		path.push_back(arr[x][y]);
	}

	return path;
}

int main()
{
	int N,M;
	cin >> N >> M ;
	vector< vector<int> > V;
	V.resize(N);
	for (int i=0;i<N;i++){
		V[i].resize(M);
		for (int j=0;j<M;j++)
			cin >> V[i][j];
	}

	vector<int> path=findPath(V);
	for (int i=0;i<path.size();i++)
		cout <<  path[i] << " " ;
	cout << endl;

	return 0;
}