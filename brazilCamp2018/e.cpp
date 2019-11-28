#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p,aux;
set<vector<int>> res;
set<vector<int>>::reverse_iterator it;
vector<bool> ver;

void bt(int s){
	if(s==n){
		aux=p;
		sort(aux.begin(),aux.end(),greater<int>());
		res.insert(aux);
		return;
	}
	for(int i=(n-s);i>0;i--){
		p.push_back(i);
		bt(s+i);
		p.pop_back();
	}
}

int main(){
	cin >> n;
	ver.assign(31,0);
	bt(0);
	for(it=res.rbegin(); it != res.rend(); ++it){
		for(int i=0;i<(*it).size();i++){
			if(i!=0)cout << "+";
			cout << (*it)[i];
		}
		cout << endl;
	}
	return 0;
}
