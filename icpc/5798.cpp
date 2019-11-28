#include <bits/stdc++.h>

using namespace std;

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 100005;

int N, B, P;

int tree[MAXN];

inline int mod(int a) {
    return ((a % P) + P) % P;
}

void add(int at, int what) {
    what %= P;
    for (at++; at < MAXN; at += at & -at) {
        tree[at] = mod(tree[at] + what);
    }
}

int query(int at) {
    int ans = 0;
    for (at++; at > 0; at -= at & -at) {
        ans = mod(ans + tree[at]);
    }
    return ans;
}

int at(int u) {
    return mod(query(u) - query(u - 1));
}

int power(int a, int b) {
    assert(b >= 0);
    if (b == 0) return 1;
    if (b & 1) { // odd
        return (1LL * a * power(a, b - 1)) % P;
    } else {
        int half = power(a, b / 2);
        return (1LL * half * half) % P;
    }
}


int main(){
    int queries;
    while (scanf(" %d %d %d %d ", &B, &P, &N, &queries) == 4) {
        if (B == 0 and P == 0 and N == 0 and queries == 0) break;
        memset(tree, 0, sizeof tree);
        while (queries--) {
            char type;
            int u, v;
            scanf(" %c %d %d ", &type, &u, &v);
            if (type == 'E') {
                add(u, -at(u));
                assert(at(u) == 0);
                add(u, (1LL * v * power(B, N - u)) % P);
            } else {
                int s = mod(query(v) - query(u - 1));
                int t = power(B, N - v);
                int ans = (1LL * s * power(t, P - 2)) % P;
                printf("%d\n", ans);
            }
        }
        puts("-");
    }
    return 0;
}
