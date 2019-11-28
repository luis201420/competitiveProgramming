#include <bits/stdc++.h>

using namespace std;

bool mycomp(const string &a, const string &b){
	return a.substr(0,2) < b.substr(0,2);
}

int main(){
	int n,cont=0;
	vector<string> s;
	while(cin >> n){
		if(n==0)break;
		if(cont!=0)cout << endl;
		s.resize(n);
		for(int i=0;i<n;i++){
			cin >> s[i];
		}
		stable_sort(s.begin(),s.end(),mycomp);
		for(int i=0;i<n;i++){
			cout << s[i] << endl;
		}
		cont++;
		s.clear();
	}
	return 0;
}
