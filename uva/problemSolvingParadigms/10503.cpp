#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<bool> vb;

vb used;
pii iniD,endD;
vpii all;
int n,m,x,y;
int ans;

void bt(int cont,int last){
	if(cont == n){
		if(last == endD.first)ans++;
		return ;
	}
	for(int i=0;i<all.size();i++){
		if(!used[i]){
			used[i]=1;
			if(all[i].first == last){
				bt(cont+1,all[i].second);
			}
			else if(all[i].second == last){
				bt(cont+1,all[i].first);
			}
			used[i]=0;
		}
	}
}

int main(){
	while(cin >> n){
		if(n==0) break;
		cin >> m;
		cin >> x >> y;
		iniD = make_pair(x,y);
		cin >> x >> y;
		endD = make_pair(x,y);
		while(m--){
			cin >> x >> y;
			all.push_back(make_pair(x,y));
		}
		used.assign(all.size(),0);
		ans=0;
		bt(0,iniD.second);
		if(ans)cout << "YES";
		else cout << "NO";
		cout << endl;
		all.clear();
	}
	return 0;
}
