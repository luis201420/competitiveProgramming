#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,v;
	cin >> n;
	vector<int> ni,np;
	int cont1,cont2;
	cont1=cont2=0;
	for(int i=0;i<n;i++){
		cin >> v;
		if(v&1){
			cont1++;
			ni.push_back(v);
		}
		else{
		       	cont2++;
			np.push_back(v);
		}
		
	}
	if(abs(cont1-cont2)<=1)cout << 0 << endl;
	else{
		int s;
		sort(ni.begin(),ni.end(),greater<int>());
		sort(np.begin(),np.end(),greater<int>());
		if(cont1>cont2){
			s=0;
			for(int i=cont2+1;i<ni.size();i++){
				s+=ni[i];
			}
		}
		else{
			s=0;
			for(int i=cont1+1;i<np.size();i++)s+=np[i];
		}
		cout << s << endl;
	}
	return 0;
}
