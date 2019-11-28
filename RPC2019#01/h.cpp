#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	vector<long long> ns(3);
	long long a,b,c,w,m,aux;
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> w;
		ns[0]=a;
		ns[1]=b;
		ns[2]=c;
		sort(ns.begin(),ns.end());
		
		if(ns[1]-ns[0]<w){
			ns[2]+=w;
		}
		else if((2*(ns[2]-ns[0]))>7){
			ns[2]+=w;
		}
		else{
			ns[0]+=w;
		}
		long long res = 0;
		res = ns[0]*ns[0];
		res += ns[1]*ns[1];
		res += ns[2]*ns[2];
		res += (7*(min(ns[0],min(ns[1],ns[2]))));
		cout << res << endl;
	}
	return 0;
}
