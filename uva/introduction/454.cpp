#include <bits/stdc++.h>

using namespace std;

vector<string> orig,comp,res,p;

int main(){
	int t;
	string line,aux;
	cin >> t;
	
	getline(cin,line);
	getline(cin,line);
	
	for(int j=0;j<t;j++){
		if(j!=0)cout << endl;

		while(getline(cin,line)){
			if(line == "")break;
			orig.push_back(line);
			aux="";
			for(int i=0;i<line.size();i++){
				if(line[i]!=' ')aux+=line[i];
			}
			sort(aux.begin(),aux.end());
			for(int i=0;i<comp.size();i++){
				if(comp[i]==aux){
					p = {orig[i],line};
					sort(p.begin(),p.end());
					res.push_back(p[0]+" = "+p[1]);
				}
			}
			comp.push_back(aux);
		}
		sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++){
			cout << res[i] << endl;
		}
		orig.clear();
		comp.clear();
		res.clear();
	}
	
	return 0;
}
