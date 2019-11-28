#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,v;
	cin >> n;
	vector<vector<int>> pos(6,vector<int>());
	for(int i=0;i<n;i++){
		cin >> v;
		if(v==4)pos[0].push_back(i);
		if(v==8)pos[1].push_back(i);
		if(v==15)pos[2].push_back(i);
		if(v==16)pos[3].push_back(i);
		if(v==23)pos[4].push_back(i);
		if(v==42)pos[5].push_back(i);
	}
	int ini,ans=0;
	vector<int>::iterator it;
	for(int i=0;i<pos[0].size();i++){
		ini=pos[0][i];
		//cerr << upper_bound(pos[1].begin(),pos[1].end(),ini)-pos[1].begin() << endl;
		it=(upper_bound(pos[1].begin(),pos[1].end(),ini));
		if(it==pos[1].end())break;
		ini=*it;
		pos[1].erase(it);
		//cerr << ini << endl;
		//cerr << upper_bound(pos[2].begin(),pos[2].end(),ini)-pos[2].begin() << endl;
		it = (upper_bound(pos[2].begin(),pos[2].end(),ini));
		if(it==pos[2].end())break;
		ini=*it;
		pos[2].erase(it);
		//cerr << ini << endl;
		//cerr << upper_bound(pos[3].begin(),pos[3].end(),ini)-pos[3].begin() << endl;
		it = (upper_bound(pos[3].begin(),pos[3].end(),ini));
		if(it==pos[3].end())break;
		ini = *it;
		pos[3].erase(it);
		//cerr << ini << endl;
		//cerr << upper_bound(pos[4].begin(),pos[4].end(),ini)-pos[4].begin() << endl;
		it = (upper_bound(pos[4].begin(),pos[4].end(),ini));
		if(it==pos[4].end())break;
		ini=*it;
		pos[4].erase(it);
		//cerr << ini << endl;
		//cerr << upper_bound(pos[5].begin(),pos[5].end(),ini)-pos[5].begin() << endl;
		it = (upper_bound(pos[5].begin(),pos[5].end(),ini));
		if(it==pos[5].end())break;
		ini = *it;
		pos[5].erase(it);
		//cerr << ini << endl;
		ans+=6;
	}
	cout << n-ans << endl;
	return 0;
}
