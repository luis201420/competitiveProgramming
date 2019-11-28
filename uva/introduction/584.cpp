#include <bits/stdc++.h>

using namespace std;

int main(){
	string game;
	int res ,aux,cont;
	while(getline(cin,game)){
		if(game == "Game Over")break;
		res = 0,cont=0;
		for(int i=game.size()-1;i>=0;i-=2){
			cont++;
			if(game[i]!='X' && game[i]!='/'){
				res+=(game[i]-'0');
				i-=2;
				if(game[i]!='/')res+=(game[i]-'0');
				else i+=2;
			}
			else if(game[i]=='/'){
				res+=10;
				if((i+2)<game.size()){
					if(game[i+2]=='X')res+=10;
					else res+=(game[i+2]-'0');
				}
				i-=2;
			}
			else if(game[i]=='X'){
				res+=10;
				aux=0;
				if((i+2)<game.size()){
					if(game[i+2]=='X')aux+=10;
					else aux+=(game[i+2]-'0');
				}
				if((i+4)<game.size()){
					if(game[i+4]=='X')aux+=10;
					else if(game[i+4]=='/')aux=10;
					else aux+=(game[i+4]-'0');
				}
				res+=aux;
			}
		}
		//cerr << cont;
		int j;
		if(cont==12){
			res-=30;
			/*j=game.size()-1;
			if(game[j]=='X')res-=10;
			else res-=(game[j]-'0');
			if(game[j-2]=='X')res-=20;
			else res-=(game[j-2]-'0');*/
		}
		if(cont==11){
			j=game.size()-1;
			if(game[j-2]=='/'){
				if(game[j]=='X')res-=10;
				else res-=(game[j]-'0');		
			}
			else{
				if(game[j]=='/')res-=10;
				else{
					res-=(game[j]-'0');
					res-=(game[j-2]-'0');
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
