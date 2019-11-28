#include<bits/stdc++.h>

using namespace std;

bool ver(string a,int k){
	string s1 = "";
	for(int i=a.size()-1;i>=0;i--)s1+=a[i];
	string s2 = "";
	int j;
	for(int i=0;i<k;i++){
		j=i;
		s2+=a[j];
		while((j+k)<a.size()){
			s2+=a[j+k];
			j+=k;
		}
	}
	string s3 = "";
	for(int i=a.size()-1;i>=(a.size()-k);i--){
		j=i;
		s3+=a[j];
		while((j-k)>=0){
			s3+=a[j-k];
			j-=k;
		}
	}
	/*cerr << s1 << endl;
	cerr << s2 << endl;
	cerr << s3 << endl;*/
	return ( s1 == s2 ) && (s2 == s3) && (s3 == a);
}

int main(){
	int t,n;
	string line,aux;
	cin >> t;
	getline(cin,line);
	for(int i=1;i<=t;i++){
		getline(cin,line);
		aux="";
		for(int j=0;j<line.size();j++){
			if(isalpha(line[j]))aux+=line[j];
		}
		line=aux;
		n = sqrt(line.size());

		cout << "Case #" << i <<":"<<endl;
		
		if(n*n == line.size()){
			if(n==1 || n==0) cout << n << endl;
			else if(ver(line,n))cout << n << endl;
			else cout << "No magic :(" << endl;
		}
		else{
			cout << "No magic :(" << endl;
		}
	}
	return 0;
}
