#include <bits/stdc++.h>

using namespace std;

struct Stone{
	long long S,E,L;
};


int main(){
	vector<Stone> Ss;
	int t,n;
	long long s,e,l,ans,auxC;
	long long ac,ap;
	cin >> t;
	for(int c=1;c<=t;c++){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> s >> e >> l;
			Ss.push_back({s,e,l});
		}
		vector<vector<int>> EN(n,vector<int>(n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					EN[i][j]=(Ss[j].E-(Ss[i].S*Ss[j].L));
					if(EN[i][j] <= 0) EN[i][j]=0;
				}
				else EN[i][j]=Ss[i].E;
			}
		}
		ans=0;
		//cerr << endl;
		ac=1;
		while(ac>0){
			ac=0;
			for(int i=0;i<n;i++){
				auxC=0;
				for(int j=0;j<n;j++){
					//cerr << EN[i][j] << " ";
					auxC+=EN[i][j];
				}
				//cerr << endl;
				if(auxC>ac){
					ap=i;
					ac=auxC;
				}
				if(auxC==ac){
					if(EN[i][i]>EN[ap][ap]){
						ap=i;
					}
				}
			}
			//cerr << endl;
			ans+=EN[ap][ap];
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(EN[i][j]==0)continue;
					if(i==ap || j==ap)EN[i][j]=0;
					else {
						EN[i][j]-=(Ss[j].L*Ss[ap].S);
						if(EN[i][j]<=0)EN[i][j]=0;
					}
				}
			}
		}

		cout <<"Case #" << c << ": "<< ans << endl;
		Ss.clear();
	}
	return 0;
}
