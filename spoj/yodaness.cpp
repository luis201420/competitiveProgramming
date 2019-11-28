#include <bits/stdc++.h>

using namespace std;

vector<int> BIT;
int n;

void update(int pos,int v){
	for(;pos<=n;pos+=(pos&-pos)){
		BIT[pos]+=v;
	}
}

int query(int k){
	int res = 0;
	for(;k>0;k-=(k&-k)){
		res += BIT[k];
	}
	return res;
}

int main(){
	int t,ans;
	map<string,int> words;
	vector<pair<int,int>> rel;
	string word;
	cin >> t;
	while(t--){
		cin >> n;
		BIT.assign(n+1,0);
		for(int i=1;i<=n;i++){
			cin >> word;
			words[word]=i;
		}
		for(int i=1;i<=n;i++){
			cin >> word;
			rel.push_back(make_pair(words[word],i));
		}
		sort(rel.begin(),rel.end());
		ans = 0;
		for(int i=rel.size()-1;i>=0;i--){
			ans += query(rel[i].second);
			update(rel[i].second,1);
		}
		cout << ans << endl;
		words.clear();
		rel.clear();
	}
	return 0;
}
