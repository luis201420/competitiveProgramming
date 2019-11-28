#include <bits/stdc++.h>

using namespace std;

bool mycomp(const pair<int,int> &p1, const pair<int,int> &p2){
	return abs(p1.first-p1.second)>abs(p2.first-p2.second);
}

int main(){
	int n,a,b;
	cin >> n;
	vector<pair<int,int>> ns;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		ns.push_back({a,b});
	}
	sort(ns.begin(),ns.end(),mycomp);
	bool v;
	int res=0;
	vector<bool> tr(n,0);
	for(int i=0;i<n;i++){
		v=0;
		for(int j=0;j<n;j++){
			if(i==j)continue;
			if(!tr[j] && ns[j].first <= ns[i].first && ns[i].first <= ns[j].second){
				v=1;
				break;
			}
			if(!tr[j] && ns[j].first <= ns[i].second && ns[i].second <= ns[j].second){
				v=1;
				break;
			}
		}
		cerr << v << endl;
		if(!v){
			res+=(abs(ns[i].first-ns[i].second)+1);
			tr[i]=1;
		}
	}
	if(res==0) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
