#include<bits/stdc++.h>

using namespace std;

/*int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

bool myComp(pair<int,int> &a, pair<int,int> &b){
	int gcd1 = gcd(a.first,a.second);
	int gcd2 = gcd(b.first,b.second);
	int a1 = a.first/gcd1;
	int a2 = a.second/gcd1;
	int b1 = b.first/gcd2;
	int b2 = b.second/gcd2;

	if(a1 == b1 && a2==b2) return a.first < b.first;
	else{
		if(a.first == b.first)return a.second > b.second;
		else return a.first<b.first;
	}
}
*/

bool myComp(pair<int,int> &a, pair<int,int> &b){
    if(a.first < b.first) return a.second < b.second;
    else return a.second >= b.second;
}
/*bool myComp(pair<int,int> &a, pair<int,int> &b){
    double r1 = double(a.first)/double(a.second);
    double r2 = double(b.first)/double(b.second);
    if(r1==r2)return a.first < b.first;
    else return r1 < r2;
}*/

int main(){
	int f,b;
	cin >> f >> b;
	vector<int> fs(f);
	for(int i=0;i<f;i++){
		cin >> fs[i];
	}
	int bs;
	vector<pair<int,int>> all;
	for(int i=0;i<b;i++){
		cin >> bs;
		for(int j=0;j<fs.size();j++){
			all.push_back({fs[j],bs});
		}
	}
	sort(all.begin(),all.end(),myComp);
	for(auto u:all){
		cout <<"("<<u.first << "," << u.second <<")"<< endl; 
	}
	return 0;
}
