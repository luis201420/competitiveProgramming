#include <bits/stdc++.h>

using namespace std;

vector<string> op;
vector<string> ns;

int sum(string a, string b){
	return atoi(a.c_str())+atoi(b.c_str());
}
int conc(string a,string b){
	return atoi((a+b).c_str());
}

void bt(int i,string r){
	if(i==ns.size()){
		op.push_back(r);
		return;
	}
	bt(i+1,r+"+");
	bt(i+1,r+"x");
	return ;
}

int main(){
	string line;
	cin >> line;
	string aux="";
	for(int i=0;i<line.size();i++){
		if(isdigit(line[i]))aux+=line[i];
		else {
			ns.push_back(aux);
			aux="";
		}
	}
	ns.push_back(aux);
	bt(1,"");
	set<int> ans;
	vector<string> na;
	int res;
	for(int i=0;i<op.size();i++){
		na.push_back(ns[0]);
		for(int j=1;j<ns.size();j++){
			if(op[i][j-1]=='x'){
				na[na.size()-1]+=ns[j];
			}
			else na.push_back(ns[j]);
		}
		res=0;
		for(int j=0;j<na.size();j++){
			//cerr << na[j] << " ";
			res+=atoi(na[j].c_str());
		}
		//cerr << endl;
		ans.insert(res);
		na.clear();
	}
	cout << ans.size() << endl;
	return 0;
}
