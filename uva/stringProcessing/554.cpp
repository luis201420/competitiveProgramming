#include <bits/stdc++.h>

using namespace std;

int main(){
	string word;
	vector<string> dict;
	cin>>word;
	while(word!="#"){
		dict.push_back(word);
		cin>>word;
	}

	string textC;
	getline(cin,textC);
	getline(cin,textC);

	vector<string> cand;
	string bestText,auxS;
	char auxC;
	int maxL=0;
	
	int cont;
	int mov = 0;
	while(mov <= 27){
		auxS = "";
		cont = 0;
		for(int i=0;i<textC.size();i++){
			
			if(textC[i] == ' ')
				auxC=('A'-1)+mov;
			else
				auxC=textC[i]+mov;
	
			auxC = 'A' + (auxC % 27);
			if(auxC > 'Z') auxC = ' ';

			for(int j=0;j<cand.size();j++){
				if(auxC == cand[j][0]){
					if(cand[j].size()==1){
						cont++;
						cand.erase(cand.begin()+j);
						j--;
					}
					else cand[j]=cand[j].substr(1);
				}
			}
			for(int j=0;j<dict.size();j++){
				if(auxC == dict[j][0]){
					cand.push_back(dict[j].substr(1));
				}
			}

			auxS+=auxC;
		}

		if(cont>maxL){
			maxL=cont;
			bestText=auxS;
		}
		cand.clear();
		mov++;
	}
	
	vector<string> ws;
	auxS="";
	for(int k=0;k<bestText.size();k++){
		if(bestText[k]==' '){
			ws.push_back(auxS);
			auxS="";
		}
		else{
			auxS+=bestText[k];
		}
	}

	cont=0;
	for(int i=0;i<ws.size()-1;i++){
		cont+=ws[i].size();
		if(cont<=60){
			cout<<ws[i];
			if((1+cont+ws[i+1].size())<=60){
				cout<<" ";
				cont++;
			}
			else{
			       	cout<<endl;
				cont=0;
			}
		}
		else {
			cout<<endl;
			cont=0;
		}
	}

	cout<<ws[ws.size()-1]<<endl;
	return 0;
}
