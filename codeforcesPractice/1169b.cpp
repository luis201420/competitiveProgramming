#include <bits/stdc++.h>

using namespace std;


int main(){
	int n,m;
	int a,b;
	cin >> n >> m;
	vector<vector<int>> cont(n,vector<int>());
	for(int i=0;i<m;i++){
		cin >> a >> b;
		cont[a-1].push_back(i);
		cont[b-1].push_back(i);
	}
	
	return 0;
}
