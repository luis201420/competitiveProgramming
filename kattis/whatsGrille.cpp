#include <bits/stdc++.h>

using namespace std;

string msg;
bool ver;
vector<string> g,res,tmp;
int n;
int cont;

void rotate(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tmp[i][j]=g[n-1-j][i];
		}
	}
	g=tmp;
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			g[i][j]=tmp[i][j];
		}
	}*/
}
void calcule(){
	char t1,t2;
	for(int i=0;i<n && ver ;i++){
		for(int j=0;j<n && ver ;j++){
			t1=g[i][j];
			t2=res[i][j];
			if(t1=='.'){
				res[i][j]=msg[cont++];
				if(t2!='!')ver=0;
			}
		}
	}
}

int main(){
  
    cin >> n;
    char t;
    ver=1;
    cont=0;
    
    g.resize(n);
    res.assign(n,string(n,'!'));
    tmp=res;
    
    for(int i=0;i<n;i++)cin >> g[i];
    cin >> msg;
    
    calcule();
    rotate();
    calcule();
    rotate();
    calcule();
    rotate();
    calcule();

    string ans = "";

    for(int i=0;i<n && ver;i++){
    	for(int j=0;j<n && ver ;j++){
		t = res[i][j];
		if(t !='!')
			ans+=t;
		else
			ver=0;
	}
    }
    if(ver) cout << ans << endl;
    else cout << "invalid grille" << endl;

    return 0;
}
