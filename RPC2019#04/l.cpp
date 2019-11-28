#include <bits/stdc++.h>

using namespace std;

int main(){
	string p;
	map<char,int> cont;
	for(int i=0;i<5;i++){
		cin >> p;
		cont[p[0]]++;
	}
	int ans=0;
	for(auto it:cont){
		ans=max(ans,it.second);
	}
	cout << ans << endl;
	return 0;
}
