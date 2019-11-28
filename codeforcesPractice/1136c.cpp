#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,v;
	cin >> n >> m;
	vector<vector<int>> contA(999),contB(999);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> v;
			contA[i+j].push_back(v);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> v;
			contB[i+j].push_back(v);
		}
	}

	bool ver = 1;

	for(int i=0;i<=(n+m-2);i++){
		sort(contA[i].begin(),contA[i].end());
		sort(contB[i].begin(),contB[i].end());
		if(contA[i]!=contB[i]){
			cout << "NO" << endl;
			ver=0;
			break;
		}
	}
	if(ver)cout << "YES" << endl;

	return 0;
}
