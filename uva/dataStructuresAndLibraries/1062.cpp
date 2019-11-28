#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<char> s;
	string line;
	bool ver;
	int cont = 1;
	while(cin >> line){
		if(line == "end")break;
		for(int i=0;i<line.size();i++){
			ver=0;
			for(int j=0;j<s.size();j++){
				if(s[j]>=line[i]){
					ver=1;
					s[j]=line[i];
					break;
				}
			}
			if(!ver)s.push_back(line[i]);
		}
		cout << "Case "<<cont++ << ": "<<s.size()<<endl;
		s.clear();
	}
	return 0;
}
