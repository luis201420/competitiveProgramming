#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,v;
	vector<int> l;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v;
		l.push_back(v);
	}
	sort(l.begin(),l.end(),greater<int>());
	int x = l[0];
	vector<int>::iterator it;
	for(int i=1;i<=sqrt(x);i++){
		if(x%i==0){
			it=find(l.begin(),l.end(),i);
			if(it!=l.end()) l.erase(it);
			if((x/i)!=i){
				it=find(l.begin(),l.end(),x/i);
				if(it!=l.end()) l.erase(it);
			}
		}
	}
	cout << x << " " << l[0] << endl;
	return 0;
}
