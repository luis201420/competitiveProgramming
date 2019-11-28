#include <bits/stdc++.h>

using namespace std;

int main(){
	string line,aux,simb;
	vector<int> numbers;
	int cont = 0;
	while(cin>>line){
		aux=simb="";
		for(int i=0;i<line.size();i++){
			if(line[i]=='+' || line[i]=='-' || line[i]=='='){
				numbers.push_back(atoi(aux.c_str()));
				simb+=line[i];
				aux="";
			}
			else{
				aux+=line[i];
			}
		}
		if(aux!="?"){
			if(simb[0]=='+'){
				if(numbers[0]+numbers[1]==atoi(aux.c_str()))cont++;
			}
			else{
				if(numbers[0]-numbers[1]==atoi(aux.c_str()))cont++;
			}
		}
		numbers.clear();
	}
	cout<<cont<<endl;
	return 0;
}
