#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x,aux;
	cin >> n;
	int m=n;
	vector<int> ans;
	aux=n;
	ans.push_back(aux);
	for(int i=1;i<n;i++){
		cin >> x;
		aux+=x;
		ans.push_back(aux);
		m=max(m,aux);
	}
	m%=n;
	vector<bool> ver(n);
	for(int i=0;i<n;i++){
		if(ans[i]-m-1 >=0)
			ver[ans[i]-m-1]=1;
	}
	bool v=1;
	for(int i=0;i<n;i++){
		v&=ver[i];
	}
	if(!v)cout << -1 << endl;
	else{
		for(int i=0;i<n;i++){
			if(i!=0)cout << " ";
			cout << ans[i]-m;
		}
		cout << endl;
	}

	return 0;
}
