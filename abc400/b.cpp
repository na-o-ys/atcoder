#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define rloop(n, i) for(int i=n;i;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

int main() {
    ll n, m; cin >> n >> m;

    ll k = 1, x = 0;
    loop (m + 1, i) {
        x += k;
        if (x > 1000000000) {
            cout << "inf" << endl;
            return 0;
        }
        k *= n;
    }
    cout << x << endl;
}