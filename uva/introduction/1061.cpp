#include<bits/stdc++.h>

using namespace std;

string conv(string a){
	string r;
	if(a.substr(0,a.size()-2)=="AA" || a.substr(0,a.size()-2)=="AO"){
		r="A";
	}
	if(a.substr(0,a.size()-2)=="BB" || a.substr(0,a.size()-2)=="BO"){
		r="B";
	}
	if(a.substr(0,a.size()-2)=="OO"){
		r="O";
	}
	if(a.substr(0,a.size()-2)=="AB"){
		r="AB";
	}
	if(a[a.size()-1]!=a[a.size()-2])r+="+";
	 if(a[a.size()-1]==a[a.size()-2]){
		 if(a[a.size()-1]=='-')r+="-";
		 else r+="+";
	 }
	 return r;
}

string sumO(string a){
	if(a=="O-"){
		return "1"+a;
	}
	if(a=="O+"){
		return "2"+a;
	}
	if(a=="AB-"){
		return "3"+a;
	}
	if(a=="AB+"){
		return "4"+a;
	}
	if(a=="B-"){
		return "5"+a;
	}
	if(a=="B+"){
		return "6"+a;
	}
	if(a=="A-"){
		return "7"+a;
	}
	if(a=="A+"){
		return "8"+a;
	}	
}

bool calChild(string a,string b,bool v,string child){
	
	set<string> ans;
	vector<char> aboA,aboB,rhA,rhB;
	
	if(a.substr(0,a.size()-1)=="A"){
		aboA={'A','O'};
	}
	if(a.substr(0,a.size()-1)=="B"){
		aboA={'B','O'};
	}
	if(a.substr(0,a.size()-1)=="AB"){
		aboA={'A','B'};
	}
	if(a.substr(0,a.size()-1)=="O"){
		aboA={'O'};
	}
	if(b.substr(0,b.size()-1)=="A"){
		aboB={'A','O'};
	}
	if(b.substr(0,b.size()-1)=="B"){
		aboB={'B','O'};
	}
	if(b.substr(0,b.size()-1)=="AB"){
		aboB={'A','B'};
	}
	if(b.substr(0,b.size()-1)=="O"){
		aboB={'O'};
	}
	if(a[a.size()-1]=='+')rhA={'+','-'};
	else rhA={'-'};

	if(b[b.size()-1]=='+')rhB={'+','-'};
	else rhB={'-'};

	string aux;
	for(int i=0;i<aboA.size();i++){
		for(int j=0;j<rhA.size();j++){
			for(int k=0;k<aboB.size();k++){
				for(int h=0;h<rhB.size();h++){
					aux=""+string(1,min(aboA[i],aboB[k]))+string(1,max(aboB[k],aboA[i]))+string(1,rhA[j])+string(1,rhB[h]);
					if(v)ans.insert(sumO(conv(aux)));
					else {if(conv(aux)==child) return 1;}
				}
			}
		}
	}
	if(v){
		if(ans.size()==1)cout << (*ans.begin()).substr(1);
		else{
			cout << "{";
			for(set<string>::iterator u=ans.begin();u!=ans.end();u++){
				if(u!=ans.begin())cout << ", ";
				cout << (*u).substr(1);
			}
			cout << "}";
		}
		return 1;
	}
	else{
		return 0;
	}
	
}

string all[8]={"A+","A-","B+","B-","O+","O-","AB+","AB-"};

int main(){
	string p1,p2,ch;
	int cont = 1;
	while(cin >> p1 >> p2 >> ch){
		if(p1 == "E" && p2=="N" && ch == "D")break;
		cout << "Case "<<cont++ << ": ";
		if(ch == "?"){
			cout << p1 << " " << p2 << " ";
			calChild(p1,p2,1,"");
			cout <<endl;
		}
		if(p2 == "?"){
			set<string> pars;
			bool p=0;
			cout << p1;
			for(int i=0;i<8;i++){
				if(calChild(p1,all[i],0,ch))pars.insert(sumO(all[i]));
			}
			if(pars.size()==0)cout << " IMPOSSIBLE ";
			else if(pars.size()==1) cout <<" "<< (*pars.begin()).substr(1)<<" ";
			else{
				cout << " {";
				for(set<string>::iterator it=pars.begin();it!=pars.end();it++){
					if(it!=pars.begin())cout << ", ";
					cout << (*it).substr(1);
				}
				cout << "} ";
			}
			cout << ch << endl;
		}
		if(p1 == "?"){
			set<string> pars;
			bool p=0;
			for(int i=0;i<8;i++){
				if(calChild(all[i],p2,0,ch))pars.insert(sumO(all[i]));
			}
			if(pars.size()==0)cout << "IMPOSSIBLE ";
			else if(pars.size()==1)cout << (*pars.begin()).substr(1)<<" ";
			else{
				cout << "{";
				for(set<string>::iterator it=pars.begin();it!=pars.end();it++){
					if(it!=pars.begin())cout << ", ";
					cout << (*it).substr(1);
				}
				cout << "} ";
			}
			cout <<p2 << " "<< ch << endl;
		}
	}
	return 0;
}
