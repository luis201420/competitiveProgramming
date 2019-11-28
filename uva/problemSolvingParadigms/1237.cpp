#include <bits/stdc++.h>

using namespace std;

vector<pair<string,pair<int,int>>> markes;

bool mycomp(pair<string,pair<int,int>> &a,pair<string,pair<int,int>> &b){
	return (a.second).first < (b.second).first;
}

int main(){
	int t,d,l,h,q,price,cont,res,i;
	string name;
	cin >> t;
	for(int k=0;k<t;k++){
		if(k!=0) cout << endl;
		cin >> d;
		while(d--){
			cin >> name >> l >> h;
			markes.push_back(make_pair(name,make_pair(l,h)));
		}
		sort(markes.begin(),markes.end(),mycomp);
		cin >> q;
		while(q--){
			cin >> price;
			cont = 0;
			i=0;
			while((markes[i].second).first <= price && i<markes.size()){
				if((markes[i].second).second >= price){
					cont++;
					res = i;
				}
				i++;
			}
			if(cont > 1 || cont == 0) cout << "UNDETERMINED" << endl;
			else cout << markes[res].first << endl;
		}
		markes.clear();
	}
	return 0;
}
