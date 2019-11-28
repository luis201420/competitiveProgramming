#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){

}

vector<bool> ver;
vector<int> primes;
void pre(){
	for(int i=2;i<ver.size();i++){
		if(ver[i]){
			primes.push_back(i);
			for(int j=i*i;j<ver.size();j+=i)ver[j]=0;
		}
	}
}

int main(){
	int n,v;
	vector<int> values;
	cin >> n;
	while(n--){
		cin >> v;
		values.push_back(v);
	}
	ver.assign(300002,1);
	pre();
	for(int i=0;i<primes.size();i++){
		for(int j=0;j<values.size();j++){
			if(values[j]%primes[i]==0){
				values.erase();
				cont++;
			}
		}
	}	
	return 0;
}
