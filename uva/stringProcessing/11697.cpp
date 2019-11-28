#include <bits/stdc++.h>

using namespace std;

int main(){
	map<char,int> cont;
	map<char,pair<int,int>> coor;
	vector<vector<char>> table;
	int n,x,y;
	string k,m;
	cin >> n;
	getline(cin,k);
	while(n--){
		table.assign(5,vector<char>(5,'Z'));
		getline(cin,k);
		getline(cin,m);
		x=0;y=0;
		for(int i=0;i<k.size();i++){
			if( k[i] != ' ' && cont[k[i]-32]==0){
				//cerr << k[i] << " - " << x << " " << y << endl;
				cont[k[i]-32]++;
				table[x][y]=(k[i]-32);
				coor[k[i]-32]=make_pair(x,y);
				y++;
				if(y==5){
					x++;
					y=0;
				}
			}
		}
		for(int i=65;i<91;i++){
			if(i!=81 && cont[i]==0){
				//cerr << char(i) << " - " << x << " " << y << endl;
				cont[i]++;
				table[x][y] = i;
				coor[i]=make_pair(x,y);
				y++;
				if(y==5){
					x++;
					y=0;
				}
			}
		}
		char c1,c2;
		for(int i=0;i<m.size();i++){
			if(m[i]==' ')continue;
			c1 = m[i];
			if((i+1)==m.size()) c2='x';
			else c2 = m[i+1];

			if(c2 == ' '){c2=m[i+2];i++;}

			if(c1 == c2) c2='x';
			else i++;

			c1-=32;c2-=32;
			//cerr << c1 << " " << c2 << " = ";

			if(coor[c1].first == coor[c2].first){
				//cerr << "C1 : ";
				cout << table[coor[c1].first][(coor[c1].second+1)%5];
				cout << table[coor[c2].first][(coor[c2].second+1)%5];
				//cerr << endl;
			}
			else if(coor[c1].second == coor[c2].second){
				//cerr << "C2 : ";
				cout << table[(coor[c1].first+1)%5][coor[c1].second];
				cout << table[(coor[c2].first+1)%5][coor[c2].second];
				//cerr << endl;
			}
			else{
				//cerr << "C3 : ";
				cout << table[coor[c1].first][coor[c2].second];
				cout << table[coor[c2].first][coor[c1].second];
				//cerr << endl;
			}
		}
		cout << endl;
		cont.clear();
		coor.clear();
	}
}
