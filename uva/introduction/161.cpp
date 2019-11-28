#include <bits/stdc++.h>

using namespace std;

bool ver(int v,int k){
	int l = ceil(float(v-k+5)/float(k));
	int r = ceil(float(v)/float(k));
	/*for(int i=l;i<=r;i++){
		if(i!=0 && i%2==0)return 1;
	}
	return 0;*/
	//cerr << l << " " << r << endl;
	return (l!=r) && (l%2==0);
}

int main(){
	vector<int> s;
	int t;
	while(cin >> t){
		s.clear();
		if(t==0){
			s.clear();
			cin >> t;
			if(t==0){
				s.clear();
				cin >> t;
				if(t==0)break;
			}
		}
		s.push_back(t);
		while(cin >> t){
			if(t==0)break;
			s.push_back(t);
		}
		/*for(auto u:s)cerr << u << " ";
		cerr << endl;*/
		bool v;
		int i;
		sort(s.begin(),s.end());
		for(i=s[0]+1;i<=18001;i++){
			v=1;
			for(int j=0;j<s.size();j++){
				v&=ver(i,s[j]);
				if(!v) break;
			}
			if(v) break;
		}
		if(!v){cout << "Signals fail to synchronise in 5 hours" << endl;continue;}
		i--;
		int h = i/3600;
		i-=(h*3600);
		int m = i/60;
		i-=(m*60);
		if(h==0)cout << "00";
		else cout << "0" << h;
		cout<< ":";
		if(m<10) cout << "0" << m;
		else cout << m;
		cout<< ":";
		if(i<10) cout << "0" << i;
		else cout << i;
		cout<< endl;
		s.clear();
	}
	return 0;
}
