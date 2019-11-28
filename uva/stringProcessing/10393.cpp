#include <bits/stdc++.h>

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ThxDem=b; i<ThxDem; ++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())
#define DBG(x) cerr <<#x << " = " << (x) << "\n"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vstr;

vstr keys = {"qaz","wsx","edc","rfvtgb"," "," ","yhnujm","ik,","ol.","p;/"};

int main(){FIN
	ll F,N,f,ansC,maxS;
	string all,s;
	vector<bool> used;
	set<string> ans;
	bool ver;
	
	while(cin >> F >> N){
		
		all="";
		used.assign(10,0);
		fore(i,0,F){
			cin >> f;
			used[f-1]=1;
			if(f == 5 || f == 6)continue;
			all+=keys[f-1];
		}
		if(used[4] && used[5]) all+=" ";
		//DBG(all);
		fore(i,0,N){
			cin >> s;
			ver=1;
			fore(j,0,SZ(s)){
				fore(k,0,SZ(all)){
					if(all[k]==s[j]){ver=0;break;}
				}
				if(!ver) break;
			}
			if(ver) ans.insert(s);
		}
		maxS = 0;
		for(string it:ans) maxS = max(int(maxS),SZ(it));
		ansC=0;
		for(string it:ans){
			if(SZ(it)==maxS) ansC++;
		}
		cout << ansC << "\n";
		for(string it:ans){
			if(SZ(it)==maxS) cout << it << "\n";
		}
		ans.clear();
	}
	return 0;
}
