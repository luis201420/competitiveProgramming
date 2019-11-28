#include <bits/stdc++.h>

using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	string c;
	int pi,pf;
	vector<string> all;
	for(int i=0;i<h;i++){
		cin >> c;
		pi=pf=-1;
		for(int j=0;j<c.size();j++){
			if(c[j]!='.'){
				if(pi==-1)pi=j;
				pf=j;
			}
		}
		all.push_back(c);
	}
	//cerr << pi << " " << pf << endl;
	int sL=0;
	for(int i=0;i<h-1;i++){
		for(int j=0;j<pi;j++){
			sL+=(all[i][j]!='.');
		}
	}
	int sC=0;
	for(int i=0;i<h-1;i++){
		for(int j=pi;j<=pf;j++){
			sC+=(all[i][j]!='.');
		}
	}
	int sR=0;
	for(int i=0;i<h-1;i++){
		for(int j=pf+1;j<w;j++){
			sR+=(all[i][j]!='.');
		}
	}
	//cerr << sL << " " << sC << " " << sR << endl;
	if( sL > (sC+sR) )cout << "left" ;
	else if( sR>(sC+sL) ) cout << "right" ;
	else cout << "balanced" ;
	cout << endl;
	return 0;
}
