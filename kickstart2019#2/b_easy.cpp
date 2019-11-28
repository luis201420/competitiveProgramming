#include <bits/stdc++.h>

using namespace std;

struct Stone{
	long long S,E,L;
};

bool myComp(const Stone &s1, const Stone &s2){
	if(s1.L==s2.L)return s1.E<s2.E;
	return s1.L<s2.L;
}

int main(){
	vector<Stone> Ss;
	int t,n;
	long long s,e,l,ans,ac,aux;
	cin >> t;
	for(int c=1;c<=t;c++){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> s >> e >> l;
			Ss.push_back({s,e,l});
		}
		sort(Ss.begin(),Ss.end(),myComp);
		ans=ac=0;	
		for(int i=0;i<n;i++){
			ans+=Ss[i].E;
			aux=((n-(i+1))*Ss[i].L*Ss[i].S);
			if(aux>Ss[i].E)aux=Ss[i].E;
			ac+=aux;
		}
		cout <<"Case #" << c << ": "<< ans-ac << endl;
		Ss.clear();
	}
	return 0;
}
