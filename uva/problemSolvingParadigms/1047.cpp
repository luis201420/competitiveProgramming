#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,m;
	int t,v,cont=1;
	int tmp,ans,aux;
	vector<vector<int>> interT;
	vector<int> values,interV;
	string mask,auxV,ansV;
	while(cin >> n >> k){
		if(n==0 && k==0) break;

		mask=string(n-k,'0')+string(k,'1');

		while(n--){
			cin >> v;
			values.push_back(v);
		}

		cin >> m;
		
		interT.assign(m,vector<int>());
		interV.assign(m,0);

		for(int i=0;i<m;i++){
			cin >> t;
			while(t--){
				cin >> v;
				interT[i].push_back(v);
			}
			cin >> v;
			interV[i]=v;
		}
		ans = 0;
		do {
			tmp=0;auxV="";
			for(int i=0;i<mask.size();i++){
				if(mask[i]=='1'){
					auxV+=to_string(i+1)+" ";
					tmp+=values[i];
				}
			}
			for(int i=0;i<interT.size();i++){
				aux=-1;
				for(int j=0;j<interT[i].size();j++){
					if(mask[interT[i][j]-1]=='1')aux++;	
				}
				if(aux>0){
					//cerr << mask << " " << i << endl;
					tmp-=(interV[i]*aux);
				}
			}
			if(ans<=tmp){
				ans=tmp;
				ansV=auxV;
			}

		} while(next_permutation(mask.begin(), mask.end()));

		cout << "Case Number  "<< cont << endl;
		cout << "Number of Customers: " << ans << endl;
		cout << "Locations recommended: "<< ansV.substr(0,ansV.size()-1) << endl<<endl;
		values.clear();
		cont++;
	}
	return 0;
}
