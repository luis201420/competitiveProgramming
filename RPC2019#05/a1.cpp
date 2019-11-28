#include <bits/stdc++.h>

using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	string c;
	vector<int> s(w,0);
	int pi,pf;
	for(int i=0;i<h;i++){
		cin >> c;
		pi=pf=-1;
		for(int j=0;j<c.size();j++){
			if(c[j]!='.'){
				s[j]++;
				if(pi==-1)pi=j;
				pf=j;
			}
		}
	}
	for(int i=1;i<w;i++){
		////cerr << s[i] << endl;
		s[i]+=s[i-1];
	}
	
	int difM=1e9;
	int r;
	for(int i=1;i<w;i++){
		if(((s[w-1]-s[i])-s[i-1])>=0 && difM>((s[w-1]-s[i])-s[i-1])){
			difM=((s[w-1]-s[i])-s[i-1]);
			r=i;
		}
	}
	if( pi<=r  && r<=pf )cout << "balanced" << endl;
	else if(pf < r) cout << "right" << endl;
	else cout << "left" << endl;
	return 0;
}
