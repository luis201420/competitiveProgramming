#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,minL,maxG,aux;
	vector<string> squad;
	vector<pair<int,int>> ones,threes;
	string line;
	while(cin >> n){
		while(n--){
			cin >> line;
			squad.push_back(line);
		}
		for(int i=0;i<squad.size();i++){
			for(int j=0;j<squad[i].size();j++){
				if(squad[i][j]=='1')ones.push_back(make_pair(i,j));
				if(squad[i][j]=='3')threes.push_back(make_pair(i,j));
			}
		}

		maxG=0;
		for(int i=0;i<ones.size();i++){
			minL=1e9;
			for(int j=0;j<threes.size();j++){
				aux=abs(ones[i].first-threes[j].first)+abs(ones[i].second-threes[j].second);
				if(minL>aux)minL=aux;
			}
			if(minL>maxG)maxG=minL;
		}

		cout << maxG << endl;
		
		squad.clear();
		ones.clear();
		threes.clear();
	}
	return 0;
}
