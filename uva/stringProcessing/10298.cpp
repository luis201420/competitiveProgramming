#include <bits/stdc++.h>

using namespace std;

int kmp(string s){
	int tam = s.size();
	vector<int> T(s.size()+1,-1);
	for(int i=1;i<=s.size();i++){
		int pos=T[i-1];
		while(pos!=-1 && s[pos]!=s[i-1]) pos = T[pos];
		T[i]=pos+1;
	}
	return tam/(tam-T[tam]);
}

int main(){
	string n;
	int res;
	while(cin >> n){
		if(n==".")break;
		res = kmp(n);
		cout << res << endl;
	}
	return 0;
}
