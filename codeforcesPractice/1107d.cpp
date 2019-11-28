#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> m,comp;

int cal(){
	bool ver;
	for(int i=n-1;i>=1;i--){
		if(n%i==0){
			ver=1;
			comp.assign(n/i,string(n/i,'-'));
			for(int x=0;x<m.size();x++){
				for(int y=0;y<m[i].size();y++){
					int n1=ceil(float(x)/float(i));
					int n2=ceil(float(y)/float(i));
					if(comp[n1][n2]!='-' && comp[n1][n2]!=m[x][y]){
						y=x=1e9;ver=0;
						break;
					}
					comp[n1][n2]=m[x][y];
				}
			}
			if(ver){
				return i;
			}
		}
	}
}

int main(){
	string s,aux;
	map<char,int> nums;
	nums['A']=10;nums['B']=11;
	nums['C']=12;nums['D']=13;
	nums['E']=14;nums['F']=15;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s;
		aux="";
		for(int j=0;j<s.size();j++){
			if(isdigit(s[j]))aux+=bitset<4>(s[j]-'0').to_string();
			else aux+=bitset<4>(nums[s[j]]).to_string();
		}
		m.push_back(aux);
		//cerr << aux << endl;
	}
	cout << cal() << endl;
	return 0;
}
