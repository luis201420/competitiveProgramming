#include <bits/stdc++.h>

using namespace std;

int dist(pair<int,int> &a,pair<int,int> &b){
	return abs(a.first-b.first) + abs(a.second-b.second);
}

int main(){
	int n;
	cin >> n;
	string line;
	vector<pair<int,int>> s,h;
	for(int i=0;i<n;i++){
		cin >> line;
		for(int j=0;j<line.size();j++){
			if(line[j]=='S')s.push_back({i,j});
			if(line[j]=='H')h.push_back({i,j});
		}
	}
	int res = 0;
	for(int i=0;i<s.size();i++){
		int m = 1e9;
		for(int j=0;j<h.size();j++){
			m=min(m,dist(s[i],h[j]));
		}
		res=max(res,m);
	}
	cout << res << endl;
	return 0;
}
