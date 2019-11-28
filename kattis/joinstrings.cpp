#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
   	cin >> n;
	
	vector<string> s(n);
	vector<list<int>> all(n,list<int>());
	
	for(int i=0;i<n;i++){
		cin >> s[i];
		all[i].push_back(i);
	}
	
	int a,b;
	for(int i=1;i<n;i++){
		cin >> a >> b;
		all[a-1].splice(all[a-1].end(),all[b-1]);
	}
	for(int i=0;i<n;i++){
		if(all[i].size()>0){
			for(auto it:all[i]){
				cout << s[it];
			}
			cout << endl;
		}
	}
	return 0;
}
