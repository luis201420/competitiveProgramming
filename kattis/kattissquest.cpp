#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,e,g,x,ans,aux;
	string s;
	cin >> n;
	map<ll,priority_queue<ll>> all;
	while(n--){
		cin >> s;
		if(s=="add"){
			cin >> e >> g;
			if(all.find(e) == all.end()) all[e] = priority_queue<ll>();
			all[e].push(g);
		}
		else{
			cin >> x;
			ans = 0;
			while(all.size() > 0){
				auto it = all.lower_bound(x);
				if(it == all.end())it--;
				while(it!=all.begin() && it->first > x) it--;
				if(it->first > x)break;
				ans += it->second.top();
				x -= it->first;
				it->second.pop();
				if(it->second.empty()) all.erase(it);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
