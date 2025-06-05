#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200001;
int n, q;
int sz[MAX_N], dep[MAX_N], par[MAX_N], top[MAX_N], in[MAX_N], out[MAX_N];

struct SegmentTree {
    bool tree[MAX_N * 2];

    void update(int p, bool val) {
        for (tree[p += n] = val; p > 1; p >>= 1) tree[p >> 1] = tree[p] | tree[p ^ 1];
    }

    bool query(int l, int r) {
        bool ret = false;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret |= tree[l++];
            if (r & 1) ret |= tree[--r];
        }
        return ret;
    }

} seg;

vector<int> t[MAX_N];

void dfs1(int here = 1) {
    sz[here] = 1;
    for (auto &there: t[here]) {
        dep[there] = dep[here] + 1;
        par[there] = here;
        dfs1(there);
        sz[here] += sz[there];
        if (sz[there] > sz[t[here][0]]) swap(there, t[here][0]);
    }
}

int counter;

void dfs2(int here = 1) {
    in[here] = ++counter;
    for (auto there: t[here]) {
        top[there] = there == t[here][0] ? top[here] : there;
        dfs2(there);
    }
    out[here] = counter;
}

bool query(int a, int b) {
    bool ret = false;
    while (top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret |= seg.query(in[st], in[a] + 1);
        a = par[st];
    }
    if (a == b) return ret;
    if (dep[a] > dep[b]) swap(a, b);
    ret |= seg.query(in[a] + 1, in[b] + 1);

    return ret;
}

void update(int a) {
    seg.update(in[a], true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;

    for (int i = 2; i <= n; ++i) {
        int a;
        cin >> a;
        t[a].push_back(i);
    }
    dfs1();
    dfs2();


    for (int i = 0; i < q; ++i) {
        int b, c, d;
        cin >> b >> c >> d;
        if (d == 0) {
            if (!query(b, c)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }

        } else {
            if (!query(b, c)) {
                cout << "YES" << '\n';
                update(b);
            } else {
                cout << "NO" << '\n';
                update(c);
            }

        }
    }


}