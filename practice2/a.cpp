#include <bits/stdc++.h>
#include <atcoder/dsu>
#define loop(n, i) for (int i = 0; i < n; i++)
#define loop1(n, i) for (int i = 1; i <= n; i++)
#define rloop(n, i) for (int i = n; i; i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using namespace atcoder;
using ll = long long;
template <class T>
using V = vector<T>;

int main()
{
    int n, q; cin >> n >> q;
    dsu d(n);
    loop(q, i) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        } else {
            cout << (d.same(u, v) ? 1 : 0) << endl;
        }
    }
}