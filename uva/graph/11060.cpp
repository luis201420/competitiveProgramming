#include <bits/stdc++.h>

using namespace std;

vector<int> contIn;
vector<vector<int>> adjIn,adjOut;
map<string,int> ids;
vector<string> beverages;
int n,m;
string beverage,b1,b2;
priority_queue<int> p;

int main(){
	int contCase = 1;
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> beverage;
			ids[beverage]=i;
			beverages.push_back(beverage);
		}
		cin >> m;
		contIn.assign(n,-1);
		adjIn.assign(n,vector<int>());
		adjOut=adjIn;
		for(int i=0;i<m;i++){
			cin >> b1 >> b2;
			adjOut[ids[b1]].push_back(ids[b2]);
			adjIn[ids[b2]].push_back(ids[b1]);
		}
		for(int i=0;i<n;i++){	
			contIn[i]=adjIn[i].size();
			if(contIn[i]==0) p.push(-i);
		}
		cout << "Case #"<<contCase << ": Dilbert should drink beverages in this order:";
		while(!p.empty()){
			int a=-(p.top());
			p.pop();
			for(int i=0;i<adjOut[a].size();i++){
				contIn[adjOut[a][i]]--;
				if(contIn[adjOut[a][i]]==0) p.push(-(adjOut[a][i]));
			}
			cout <<" "<< beverages[a];
		}
		cout << "."<<endl<<endl;
		ids.clear();
		beverages.clear();
		contCase++;
	}
	return 0;
}
