#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,idmw;
	double m,q;
	string s;double w,p;
	double r;
	cin >> t;
	vector<string> names;
	vector<double> ws,ps;
	
	cout << setprecision(1) << fixed;
	
	for(int i=1;i<=t;i++){
		cin >> n >> m >> q;
		r=q/m;
		while(n--){
			cin >> s >> w >> p;
			if(p==100){
				w*=r;
				idmw=names.size();
			}
			names.push_back(s);
			ws.push_back(w);
			ps.push_back(p);
		}
		
		cout << "Recipe # " << i << endl;
		for(int j=0;j<names.size();j++){
			cout << names[j] << " ";
			if(j!=idmw)cout << (ws[idmw]*ps[j])/100.0;
			else cout << ws[j];
			cout << endl;
		}
		cout << string(40,'-') << endl;
		names.clear();
		ws.clear();
		ps.clear();
	}
	return 0;
}
