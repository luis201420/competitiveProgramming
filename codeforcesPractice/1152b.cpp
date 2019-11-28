#include <bits/stdc++.h>

using namespace std;

int get_n(int x){
	string s="";
	while(x>0){
		s=to_string(x%2)+s;
		x/=2;
	}
	int i=0;
	while(i<s.size() && s[i]!='0'){
		i++;
	}
	return s.size()-i;
}

int main(){
	int x,t,n,cont;
	bool op;
	cin >> x;
	t=0;
	cont=0;
	op=1;
	vector<int> ans;
	for(;t<40;t++){
		n=get_n(x);
		if(n==0)break;
		if(op){
			x=x^(int(1<<n)-1);
			ans.push_back(n);
		}
		else{
			x++;
		}
		op^=1;
		cont++;
	}
	cout << cont << endl;
	for(int i=0;i<ans.size();i++){
		if(i!=0)cout<<" ";
		cout << ans[i];
	}
	if(cont>0)cout << endl;
	return 0;
}
