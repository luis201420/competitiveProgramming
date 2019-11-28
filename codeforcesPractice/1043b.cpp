#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v,last=0;
	vector<int> dif;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		dif.push_back(v-last);
		last=v;
	}

	set<int> res;
	res.insert(n);
	int k = n-1;
	bool ver;
	
	while(k>0){
		ver = 1;
		for(int i=0;i<dif.size();i++){
			if(dif[i]!=dif[i%k]){
				ver=0;
				break;
			}
		}
		if(ver)res.insert(k);
		k--;
	}

	set<int>::iterator it;
	cout << res.size() << endl;
	for(it=res.begin();it!=res.end();it++){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
