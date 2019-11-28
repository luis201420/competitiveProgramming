#include <bits/stdc++.h>

using namespace std;

int t,n,p,v;
vector<int> bars;

bool ver(){
	int s;
	for(int i=0;i<(1<<p);i++){
		s = 0;
		//cerr << i << endl;
		for(int j=0;j<p;j++){
			if(i&(1<<j))s+=bars[j];
		}
		if(s == n) return 1;
	}
	return 0;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> p;
		for(int i=0;i<p;i++){
			cin >> v;
			bars.push_back(v);
		}
		if(ver()) cout << "YES" << endl;
		else cout << "NO" << endl;
		bars.clear();	
	}
	return 0;
}
