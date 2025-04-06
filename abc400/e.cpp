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
    V<ll> primes;
    primes.push_back(2);
    for (int i = 3; i <= 1000000; i += 2) {
        bool is_prime = true;
        for (int j = 0; primes[j] * primes[j] <= i && j < primes.size(); j++) {
            if (i % primes[j] == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(i);
    }

    V<ll> good;
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i + 1; j < primes.size() && primes[i] * primes[j] <= 1000000; j++) {
            for (ll p = primes[i]; p * primes[j] <= 1000000; p *= primes[i]) {
                for (ll q = primes[j]; p * q <= 1000000; q *= primes[j]) {
                    good.push_back(p * q);
                }
            }
        }
    }
    sort(good.begin(), good.end());
    
    int q; cin >> q;
    while (q--) {
        ll n; cin >> n;

        int left = 0, right = good.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (good[mid] * good[mid] <= n) left = mid + 1;
            else right = mid;
        }
        cout << good[left - 1] * good[left - 1] << endl;
    }
}