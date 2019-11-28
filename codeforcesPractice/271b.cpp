#include <bits/stdc++.h>

using namespace std;

bool dist(int &n){
	string ns = to_string(n);
	for(int i=0;i<ns.size();i++){
		for(int j=i+1;j<ns.size();j++){
			if(ns[i]==ns[j])return true;
		}
	}
	return false;
}

int main(){
	int n;
	cin >> n;
	n++;
	while(dist(n)){
		n++;
	}
	cout << n << endl;
	return 0;
}
