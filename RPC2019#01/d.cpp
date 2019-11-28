#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<long long> correct,all;
	vector<string> ss,res;
	int n,m;
	string s;
	while(cin >> n){
		correct.assign(n,0);
		all=correct;
		while(n--){
			cin >> s;
			ss.push_back(s);
		}
		res=ss;
		string a ,b, c;
		cin >> m;
		while(m--){
			cin >> a >> b >> c;
			for(int i=0;i<ss.size();i++){
				if(ss[i]==a){
					res[i]=b;
					if(c[0]=='c')correct[i]++;
					all[i]++;
				}
			}
		}
		long long res1=1,res2=1;
		for(int i=0;i<correct.size();i++){
			res1*=correct[i];
			res2*=all[i];
		}
		if((res2)==1){
			for(int i=0;i<res.size();i++){
				if(i!=0)cout << " ";
				cout << res[i];
			}
			cout << endl;
			if(res1==0)cout << "incorrect" << endl;
			else cout << "correct" << endl;
		}
		else{
			cout << res1 << " correct"<<endl;
			cout << res2-res1 << " incorrect" << endl;
		}
		ss.clear();
	}
	return 0;
}
