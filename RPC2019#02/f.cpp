#include<bits/stdc++.h>

using namespace std;

int main(){
	string line;
	cin >> line;
	long long cont[10]={0};
	for(int i=0;i<line.size();i++){
		cont[line[i]-'0']++;
	}
	int res = 1;
	for(int i=2;i<10;i++){
		if(cont[res]>cont[i])res=i;
	}
	if (cont[0]<cont[res]){
		res=0;
		cout << "1" << string(cont[0]+1,'0') << endl;
	}
	else{
		cout << string(cont[res]+1,char(res+'0')) << endl;
	}
	return 0;
}
