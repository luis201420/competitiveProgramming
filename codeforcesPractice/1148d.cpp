#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> all;

bool myComp1(const int &p1,const int &p2){
	return all[p1].second > all[p2].second;
}

bool myComp2(const int &p1,const int &p2){
	return all[p1].second < all[p2].second;
}

int main(){
	int n;
	cin >> n;
	vector<int>A,B;
	int a,b;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		all.push_back({a,b});
		if(a<b)A.push_back(i);
		else B.push_back(i);
	}
	if(A.size()>B.size()){
		cout << A.size() << endl;
		sort(A.begin(),A.end(),myComp1);
		for(int i=0;i<A.size();i++){
			if(i!=0)cout << " ";
			cout << A[i]+1;
		}
		cout << endl;
	}
	else{
		cout << B.size() << endl;
		sort(B.begin(),B.end(),myComp2);
		for(int i=0;i<B.size();i++){
			if(i!=0) cout << " ";
			cout << B[i]+1;
		}
		cout << endl;
	}
	return 0;
}
