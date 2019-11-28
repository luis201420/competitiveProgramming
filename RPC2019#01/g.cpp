#include <bits/stdc++.h>

using namespace std;

int main(){
	string s1,s2;
	int n1,n2,w;
	while(cin >> s1 >> n1){
		cin >> s2 >> n2;
		if(s1[0]=='B' && s2[0]=='D'){
			if((n1*2)<=n2)w=2;
			else w=1;
		}
		if(s1[0]=='D' && s2[0]=='C'){
			if((n1*2)<=n2)w=2;
			else w=1;
		}
		if(s1[0]=='C' && s2[0]=='B'){
			if((n1*2)<=n2)w=2;
			else w=1;
		}
		if(s1[0]=='D' && s2[0]=='B'){
			if((n2*2)<=n1)w=1;
			else w=2;
		}
		if(s1[0]=='C' && s2[0]=='D'){
			if((n2*2)<=n1)w=1;
			else w=2;
		}
		if(s1[0]=='B' && s2[0]=='C'){
			if((n2*2)<=n1)w=1;
			else w=2;
		}
		if(s1[0]==s2[0]){
			if(n1==n2)w=3;
			if(n1>n2)w=1;
			if(n2>n1) w=2;
		}
		if(w==3)cout << "Draw";
		if(w==2)cout << "Naebbirac";
		if(w==1)cout << "Tobby";
		cout << endl;
	}
	return 0;
}
