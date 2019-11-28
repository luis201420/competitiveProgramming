#include <bits/stdc++.h>

using namespace std;

vector<string> req;
vector<pair<string,pair<float,float>>> nameP;
vector<vector<string>> reqP;

bool myComp(const pair<string,pair<float,float>>& a,const pair<string,pair<float,float>>& b){
	if((a.second).second == (b.second).second)
		return (a.second).first < (b.second).first;
	else
		return (a.second).second > (b.second).second;
}

int main(){
	string s;
	int n,p,cont=1;
	float f,r;
	while(cin >> n >> p){
		if((n+p)==0)break;
		if(cont!=1)cout << endl;
		getline(cin,s);
		for(int i=0;i<n;i++){
			getline(cin,s);
			req.push_back(s);
		}
		for(int i=0;i<p;i++){
			getline(cin,s);
			cin >> f >> r;
			nameP.push_back({s,{f,(r/float(n))}});
			getline(cin,s);
			reqP.push_back(vector<string>());
			for(int j=0;j<r;j++){
				getline(cin,s);
				reqP[reqP.size()-1].push_back(s);
			}
		}
		sort(nameP.begin(),nameP.end(),myComp);
		cout << "RFP #"<<cont<<endl;
		cout << nameP[0].first << endl;
		nameP.clear();
		req.clear();
		reqP.clear();
		cont++;
	}
	return 0;
}
