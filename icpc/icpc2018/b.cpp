#include <bits/stdc++.h>

using namespace std;

int main(){
	map<int,bool> used;
	vector<int> arc;
	int n,v,s;
	cin >> n;
	s=0;
	while(n--){
		cin >> v;
		arc.push_back(v);
		s+=v;
		used[s]=1;
	}
	used[s]=0;
	used[0]=1;
	if(s&1)cout << "N";
	else{
		int h=s/2, cont = 0, s2=0;
		for(int i=0;i<arc.size();i++){
			s2+=arc[i];
			if(used[(s2+h)%s])cont++;
		}
		if(cont>=4)cout << "Y";
		else cout << "N";
	}
	cout << endl;
	return 0;
}
