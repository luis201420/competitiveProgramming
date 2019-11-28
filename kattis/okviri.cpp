#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	cout << ".";
	for(int i=1;i<=s.size();i++){
		if(i%3==0)cout <<".*.";
		else cout << ".#.";
		cout << ".";
	}
	cout <<endl;
	cout << ".";
	for(int i=1;i<=s.size();i++){
		if(i%3==0)cout <<"*.*";
		else cout << "#.#";
		cout << ".";
	}
	cout <<endl;
	string l = ".";
	for(int i=1;i<=s.size();i++){
		if(i%3==0){
			l[l.size()-1]='*';
			l+=".";
			l+=s[i-1];
			l+=".*";
		}
		else{
			if(l[l.size()-1]!='*')l[l.size()-1]='#';
			l+=".";
			l+=s[i-1];
			l+=".#";
		}
	}
	cout << l << endl;	
	cout << ".";
	for(int i=1;i<=s.size();i++){
		if(i%3==0)cout <<"*.*";
		else cout << "#.#";
		cout << ".";
	}
	cout <<endl;
	cout << ".";
	for(int i=1;i<=s.size();i++){
		if(i%3==0)cout <<".*.";
		else cout << ".#.";
		cout << ".";
	}
	cout <<endl;
	return 0;
}
