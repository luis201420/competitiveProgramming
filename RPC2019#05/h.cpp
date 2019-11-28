#include <bits/stdc++.h>

using namespace std;

int main(){
	set<char> mO;
	vector<int> contI(26,0),contO(26,0);
	string molI,molO;
	int cant;
	cin >> molI >> cant;
	cin >> molO;
	string aux;
	char cC;
	for(int i=0;i<molI.size();i++){
		aux="";
		cC=molI[i];
		while(i+1<molI.size() && isdigit(molI[i+1])){
			aux+=molI[i+1];
			i++;
		}
		if(aux.size()==0) aux="1";
		contI[cC-'A']+=(atoi(aux.c_str())*cant);
	}
	
	for(int i=0;i<molO.size();i++){
		aux="";
		cC=molO[i];
		while((i+1)<molO.size() && isdigit(molO[i+1])){
			aux+=molO[i+1];
			i++;
		}
		if(aux.size()==0) aux="1";
		contO[cC-'A']+=(atoi(aux.c_str()));
		mO.insert(cC);
	}
	int ans=1e9;
	int aux2=0;
	for(int i=0;i<26;i++){
		if(contI[i]==0 || contO[i]==0)continue;
		ans=min(ans,contI[i]/contO[i]);
		aux2++;
	}
	if(aux2==mO.size())cout << ans << endl;
	else cout << 0 << endl;
	return 0;
}
