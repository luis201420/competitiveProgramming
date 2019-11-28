#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,v;
	vector<int> towns;
	cin >> n;
	while(n--){
		cin >> v;
		towns.push_back(v);
	}

	int res = 0;
	for(int i=1;i<towns.size();i++){
		if(towns[i]<towns[res]){
			res=i;
		}
	}

	bool ver = 1;

	for(int i=0;i<towns.size();i++){
		if(i!=res && towns[i]==towns[res])ver=0;
	}

	if(ver) cout << res+1;
	else cout << "Still Rozdil";

	cout << endl;

	return 0;
}
