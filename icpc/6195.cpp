#include <bits/stdc++.h>

using namespace std;

int ans,n,m;
vector<vector<int>> adjIn,adjOut;
vector<int> degrees;

int main(){
	int a,b,cont,current;
	while(cin >> n >> m){
		if(n==0 && m==0)break;
		adjIn.assign(n,vector<int>());
		adjOut=adjIn;
		degrees.assign(n,0);
		for(int i=0;i<m;i++){
			cin >> a >> b;
			adjOut[a-1].push_back(b-1);
			adjIn[b-1].push_back(a-1);
		}
		cont=0;
		for(int i=0;i<n;i++){
			degrees[i]=adjIn[i].size();
			if(degrees[i]==0){
				cont++;
				current=i;
			}
		}
		if(cont==0) cout << 0;
		else if(cont>1)cout << 2;
		else{
			int k;
			for(k=0;k<(n-1);k++){
				//cerr << current;
				cont = 0;
				for(int i=0;i<adjOut[current].size();i++){
					degrees[adjOut[current][i]]--;
					if(degrees[adjOut[current][i]]==0){
						cont++;
						current=adjOut[current][i];
					}	
				}
				if(cont == 0 || cont > 1) {
					if(cont==0)cout << 0;
					else cout << 2;
					break;
				}
			}
			//cerr << endl;
			if(k==(n-1))cout << 1;
		}
		cout << endl;
	}
	return 0;
}
