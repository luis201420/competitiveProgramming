#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> ns;

int cal(const pair<int,int> &x){
	if(x.first > x.second) return 0;
	return (x.second-x.first+1); 
}

bool myComp(const pair<int,int> &x, const pair<int,int> &y){
	return cal(x)<cal(y);
}

void update(){
	int pos = 0;
	vector<pair<int,int>> aux;
	for(int i=1;i<ns.size();i++){
		if(ns[i].first <= ns[pos].first && ns[pos].second <= ns[i].second){
			if(ns[i].first<=ns[pos].first-1)aux.push_back({ns[i].first,ns[pos].first-1});
			if(ns[pos].second+1<=ns[i].second)aux.push_back({ns[pos].second+1,ns[i].second});
		}
		else if(ns[i].first <= ns[pos].second && ns[pos].second <= ns[i].second){
			if(ns[pos].second+1<=ns[i].second)aux.push_back({ns[pos].second+1,ns[i].second});
		}
		else if(ns[i].second >= ns[pos].first && ns[pos].first >= ns[i].first){
			if(ns[i].first<=ns[pos].first-1)aux.push_back({ns[i].first,ns[pos].first-1});
		}
		else{
			if(ns[i].first<=ns[i].second)aux.push_back({ns[i].first,ns[i].second});
		}
	}
	sort(aux.begin(),aux.end(),myComp);
	ns=aux;
}

int main(){
	int t,n,q,res;
	int a,b;
	cin >> t;
	for(int k=1;k<=t;k++){
		cin >> n >> q;
		for(int i=0;i<q;i++){
			cin >> a >> b;
			ns.push_back({a,b});
		}
		sort(ns.begin(),ns.end(),myComp);
		res=1e9;
		while(ns.size()>0){
			res=min(res,cal(ns[0]));
			cerr << ns[0].first << " " << ns[0].second << endl;
			if(cal(ns[0])){
				update();
			}
		}
		cout << res << endl;
		ns.clear();
	}
	return 0;
}
