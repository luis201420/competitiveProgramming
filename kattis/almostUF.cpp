// Example program
#include <bits/stdc++.h>

using namespace std;

vector<long long> link,sizeT,sumT,refT;
int n,p;

int findT(int x){
    if(x == link[x]) return x;
    return link[x]=findT(link[x]);
}

bool same(int a,int b){
    return findT(a) == findT(b);
}

void uniteA(int a,int b){
    a = findT(refT[a]);
    b = findT(refT[b]);
    if(sizeT[a]<sizeT[b]) swap(a,b);
    sizeT[a]+=sizeT[b];
    link[b]=a;
    sumT[a]+=sumT[b];
}

// a -> b
void uniteB(int a,int b){
    int r = refT[a];
    int p = findT(r);
    sizeT[p]--;
    sumT[p]-=(a+1);
    refT[a]=n;
    link[n]=findT(refT[b]);
    sizeT[findT(refT[b])]++;
    sumT[findT(refT[b])]+=(a+1);
    n++;
}

int main()
{
    //n=5;p=7;
    link.resize(200000);
    sumT.resize(200000);
    refT.resize(200000);
    while(cin >> n >> p){
        sizeT.assign(200000,1);
        for(int i=0;i<200000;i++){
            link[i]=i;
            sumT[i]=i+1;
            refT[i]=i;
        }
        int op,i1,i2;
        while(p--){
            cin >> op;
            if(op==1){
                cin >> i1 >> i2;
                if(!same(refT[i1-1],refT[i2-1]))
                    uniteA(i1-1,i2-1);
            }
            if(op==2){
                cin >> i1 >> i2;
                if(!same(refT[i1-1],refT[i2-1]))
                    uniteB(i1-1,i2-1);
            }
            if(op==3){
                cin >> i1;
                cout << sizeT[findT(refT[i1-1])] << " " << sumT[findT(refT[i1-1])] << endl;
            }
        }
    }
    return 0;
}

