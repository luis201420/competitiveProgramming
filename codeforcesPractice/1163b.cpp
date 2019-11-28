#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> ns(n);
	vector<int> cont(10,0);
	for(int i=0;i<n;i++){
		cin >> ns[i];
		cont[ns[i]-1]++;

	}
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	set<int> aux;
	bool v;
	for(int i=0;i<10;i++){
		cont[i]--;
		v=1;
		for(int j=0;j<10;j++){
			if(cont[j]==0)continue;
			aux.insert(cont[j]);
		}
		if(aux.size()==1){
			cout << n << endl;
			return 0;
		}
		aux.clear();
		cont[i]++;
	}
	
	for(int i=n-1;i>=0;i--){
		cont[ns[i]-1]--;
		for(int j=0;j<10;j++){
			cont[j]--;
			v=1;
			for(int k=0;k<10;k++){
				if(cont[k]==0) continue;
				aux.insert(cont[k]);
			}
			if(aux.size()==1){
				cout << i << endl;
				return 0;
			}
			aux.clear();
			cont[j]++;
		}
	}
	
	return 0;
}
