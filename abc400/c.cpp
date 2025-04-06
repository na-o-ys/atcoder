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
    ll n; cin >> n;

    ll ans = 0;
    for (ll b = 1; b * b <= n; b += 2) {
        ll k = n / (b * b);
        // INSP(b);
        // INSP(k);
        for (ll base = 2; base <= k; base *= 2) {
            // INSP(base);
            ans++;
        }
    }
    cout << ans << endl;
}