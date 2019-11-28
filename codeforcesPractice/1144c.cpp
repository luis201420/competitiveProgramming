#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,va;
	cin >> n;
	map<int,int> cont;
	vector<int> ns;
	for(int i=0;i<n;i++){
		cin >> va;
		cont[va]++;
		ns.push_back(va);
	}
	vector<int> a,b;
	bool v=1;
	for(auto u:cont){
		if(u.second > 2)v=0;
		else if(u.second == 2) a.push_back(u.first);
		b.push_back(u.first);
	}
	if(!v)cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end(),greater<int>());
		cout << a.size() << endl;
		for(int i=0;i<a.size();i++){
			if(i!=0)cout << " ";
			cout<<a[i]; 
		}
		cout << endl;
		cout << b.size() << endl;
		for(int i=0;i<b.size();i++){
			if(i!=0)cout << " ";
			cout << b[i];
		}
		cout << endl;
	}
	return 0;
}
