#include <bits/stdc++.h>

using namespace std;

string firstC(string &a){
	if(a=="Left")return "Right";
	if(a=="Right")return "Forward";
	else return "Left";
}
string secondC(string &a){
	if(a=="Left")return "Forward";
	if(a=="Right")return "Left";
	else return "Right";
}

int changeDir(int cdir,string mov){
	if(mov == "Left")cdir--;
	if(mov == "Right")cdir++;

	if(cdir < 0)cdir+=4;
	if(cdir > 3)cdir-=4;
	return cdir;
}

void move(int &px,int &py,int &pdir, string mov){
	if(mov=="Forward"){
		if(pdir==0)py++;
		if(pdir==1)px++;
		if(pdir==2)py--;
		if(pdir==3)px--;
	}
	else{
		pdir=changeDir(pdir,mov);
	}
}

bool process(int dx,int dy,vector<string> &m){
	int cx = 0;
	int cy = 0;
	int dir = 0;

	for(int i=0;i<m.size();i++){
		move(cx,cy,dir,m[i]);
	}
	if(cx==dx && cy==dy)return 1;
	
	return 0;
}

int main(){
	int x,y,n;
	cin >> x >> y;
	cin >> n;
	vector<string> m(n);
	for(int i=0;i<n;i++){
		cin >> m[i];
	}

	string orig;
	for(int i=0;i<n;i++){
		orig=m[i];
		m[i]=firstC(orig);
		if(process(x,y,m)){
			cout << i+1 << " " << m[i] << endl;
			break;
		}
		m[i]=secondC(orig);
		if(process(x,y,m)){
			cout << i+1 << " " << m[i] << endl;
			break;
		}
		m[i]=orig;
	}
	return 0;
}
