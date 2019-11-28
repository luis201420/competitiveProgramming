#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> bottles,couries;

inline int dm(pair<int,int> p,pair<int,int> q){
	return abs(p.first-q.first)+abs(p.second-q.second);
}

void f(){
	
}

int main(){
	int n,m,a,b,res;
	pair<int,int> mini;
	while(cin >> n >> m){
		while(n--){
			cin >> a >> b;
			bottles.push_back({a,b});
		}
		while(m--){
			cin >> a >> b;
			couries.push_back({a,b});
		}
		cin >> a >> b;
		res = 0;
		f();
		cout << res << endl;
	}
	return 0;
}
