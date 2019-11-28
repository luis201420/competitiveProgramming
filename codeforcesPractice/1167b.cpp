#include <bits/stdc++.h>

using namespace std;

int l[6] = {4,8,15,16,23,42};

int main(){
	map<int,bool> ver;
	ver[4]=ver[8]=ver[15]=ver[15]=ver[16]=ver[23]=ver[42]=1;
	int v,a1,a2;
	vector<int> res(6);
	map<int,int> cont;
	cout << "? 1 6" << endl << flush;
	cin >> v;
	for(int i=0;i<6;i++){
		if(v%l[i]==0 && ver[v/l[i]] && (v/l[i])!=l[i]){
			a1=l[i];
			a2=(v/l[i]);
			break;
		}
	}
	cout << "? 1 5" << endl << flush;
	cin >> v;
	if(v%a1==0 && ver[v/a1]){
		res[0] = a1;
		res[4] = v/a1;
		res[5] = a2;
	}
	else{
		res[0] = a2;
		res[4] = v/a2;
		res[5] = a1;
	}

	cont[res[0]]++;
	cont[res[4]]++;
	cont[res[5]]++;

	cout << "? 2 5" << endl << flush;
	cin >> v;
	res[1]=v/res[4];
	cont[res[1]]++;
	
	cout << "? 2 4" << endl << flush;
	cin >> v ;
	res[3]=v/res[1];
	cont[res[3]]++;
	
	for(int i=0;i<6;i++){
		if(cont[l[i]]==0){
			res[2]=l[i];
			break;
		}
	}
	
	cout << "!";
	for(int i=0;i<6;i++){
		cout << " " << res[i];
	}
	cout << endl;
	return 0;
}
