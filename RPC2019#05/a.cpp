#include <bits/stdc++.h>

using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	string c;
	int pi,pf;
	int cont=0;
	double s=0.0;
	for(int i=0;i<h;i++){
		cin >> c;
		pi=-1;
		for(int j=0;j<c.size();j++){
			if(c[j]!='.'){
				s+=(double(j));
				cont++;
				if(pi==-1)pi=j;
				pf=j;
			}
		}
	}
	if(cont == 0){
		cout << "balanced" << endl;
		return 0;
	}
	//cerr << cont << endl;
	//cerr << s << endl;
	s/=double(cont);
	s=round(s);
	//cerr << s << endl;
	//cerr << pi << " " << pf << endl;
	if(s>=pi && s<=pf)cout << "balanced" << endl;
	else if(s>pf) cout << "right" << endl;
	else cout << "left" << endl;
	return 0;
}
