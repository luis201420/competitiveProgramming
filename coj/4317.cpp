#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string line,res;
	getline(cin,line);
	while(n--){
		getline(cin,line);
		res="";
		for(int i=0;i<line.size();i++){
			if(line[i]=='a'||line[i]=='e'||line[i]=='i'||line[i]=='o'||line[i]=='u'){
				res+=line[i];
				res+="p";
				res+=line[i];
			}
			else
				res+=line[i];
		}
		printf("%s\n",res.c_str());
	}
	return 0;
}
