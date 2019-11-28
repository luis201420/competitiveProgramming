#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v;
	cin >> n;
	set<int> ns;
	for(int i=0;i<n;i++){
		cin >> v;
		ns.insert(v);
	}

	if(n==1 || ns.size()==1){
		cout << 0 << endl;
		return 0;
	}

	if(ns.size()>3){
		cout << -1 << endl;
		return 0;
	}

	vector<int> aux;
	for(auto it:ns){
		aux.push_back(it);
	}
	set<int> res;
	for(int i=0;i<aux.size()-1;i++){
		res.insert(aux[i+1]-aux[i]);
	}
	if(res.size()==1){
		int ans = *res.begin();
		if(ns.size()==2 && ans%2==0)ans/=2;
		cout << ans  << endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0;
}
