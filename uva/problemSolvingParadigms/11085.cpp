#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> list_board;
typedef vector<int> board;
typedef vector<bool> vb;

const int n = 8;
board ans;
list_board list_ans;
vb col,diag1,diag2;

void search(int y){
	if(y==n){
		list_ans.push_back(ans);
		for(int i=0;i<ans.size();i++){
			cerr << ans[i]<< " ";
		}
		cerr << endl;
		return;
	}
	for(int x=0;x<n;x++){
		if(col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
		col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
		ans[x]=y;
		search(y+1);
		col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	}
}

int main(){
	col.assign(n,0);
	diag1 = diag2 = col;
	ans.assign(n,0);
	search(0);

	cerr << list_ans.size() << endl;
	
	board query;
	int v;
	int aux,mini;

	while(cin >> v){
		query.push_back(v-1);
		for(int i=0;i<7;i++){
			cin >> v;
			query.push_back(v-1);
		}
		mini=10000;
		for(int i=0;i<list_ans.size();i++){
			aux=0;
			for(int j=0;j<list_ans[i].size();j++){
				aux+=abs(list_ans[i][j]-query[j]);
			}
			if(mini>aux)mini=aux;
		}

		cout << mini << endl;

		query.clear();
	}
	return 0;
}
