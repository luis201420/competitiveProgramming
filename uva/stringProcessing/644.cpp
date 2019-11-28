#include <bits/stdc++.h>

using namespace std;

bool comp (string &a,string &b){
	int minSize = min(a.size(),b.size());
	return a.substr(0,minSize) == b.substr(0,minSize);
}
int main(){
	
	string line;
	vector<string> content;
	int cont=0;
	bool ver;

	while(cin>>line){

		cont++;
		ver=true;
		content.clear();

		content.push_back(line);
		while(line!="9"){
			cin>>line;
			content.push_back(line);
		}

		sort(content.begin(),content.end());
		for(int i=1;i<content.size();i++){
			if(comp(content[i-1],content[i])){
				ver=false;
				break;
			}
		}

		if(ver)cout<<"Set "<<cont<<" is immediately decodable\n";
		else cout<<"Set "<<cont<<" is not immediately decodable\n";
	}

	return 0;
}
