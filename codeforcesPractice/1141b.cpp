#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v;
	cin >> n;
	vector<int> ns(n),ans;
	for(int i=0;i<n;i++){
		cin >> ns[i];
	}
	int res=0;
	int cont=0;
	bool p=0;
	int f,e;
	for(int i=0;i<n;i++){
		if(ns[i]==1){
			cont++;
		}
		else{
			res=max(res,cont);
			ans.push_back(cont);
			cont=0;
		}
	}
	res=max(res,cont);
	ans.push_back(cont);
	if(ans.size()>1)res=max(res,ans[ans.size()-1]+ans[0]);

	cout << res << endl;
	return 0;
}
