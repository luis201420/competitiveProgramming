#include <bits/stdc++.h>

using namespace std;

string current;

void update(string n){
	if(current=="+x"){
		//current=n;
		if(n=="+y"){
			current="+y";
		}
		if(n=="-y"){
			current="-y";
		}
		if(n=="+z"){
			current="+z";
		}
		if(n=="-z"){
			current="-z";
		}
	}
	else if(current=="-x"){	
		if(n=="+y"){
			current="-y";
		}
		if(n=="-y"){
			current="+y";
		}
		if(n=="+z"){
			current="-z";
		}
		if(n=="-z"){
			current="+z";
		}
	}
	else if(current=="+y"){	
		if(n=="+y"){
			current="-x";
		}
		if(n=="-y"){
			current="+x";
		}
		if(n=="+z"){
			current="+y";
		}
		if(n=="-z"){
			current="+y";
		}
	}
	else if(current=="-y"){
		if(n=="+y"){
			current="+x";
		}
		if(n=="-y"){
			current="-x";
		}
		if(n=="+z"){
			current="-y";
		}
		if(n=="-z"){
			current="-y";
		}
	}
	else if(current=="+z"){
		if(n=="+y"){
			current="+z";
		}
		if(n=="-y"){
			current="+z";
		}
		if(n=="+z"){
			current="-x";
		}
		if(n=="-z"){
			current="+x";
		}
	}
	else if(current=="-z"){
		if(n=="+y"){
			current="-z";
		}
		if(n=="-y"){
			current="-z";
		}
		if(n=="+z"){
			current="+x";
		}
		if(n=="-z"){
			current="-x";
		}
	}
}

int main(){
	int l;
	string s;
	while(cin >> l){
		if(l==0)break;
		current = "+x";
		for(int i=1;i<l;i++){
			cin >> s;
			if(s!="No"){
				update(s);
			}
		}
		cout << current << endl;
	}
	return 0;
}
