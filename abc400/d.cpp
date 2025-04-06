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
int INF = 1e9;

V<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    int h, w; cin >> h >> w;
    V<string> S(h);
    loop (h, i) cin >> S[i];
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;

    V<V<int>> dp(h, V<int>(w, INF));
    queue<pair<int, int>> q;

    q.push({a, b});
    dp[a][b] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (S[nx][ny] == '#') continue;
            if (dp[nx][ny] <= dp[x][y]) continue;
            dp[nx][ny] = 0;
            q.push({nx, ny});
        }
    }

    queue<tuple<int, int, int>> q2;
    loop (h, i) loop (w, j) if (dp[i][j] == 0) q2.push({i, j, 0});
    while (!q2.empty()) {
        auto [x, y, v] = q2.front(); q2.pop();
        for (auto [dx, dy] : dir) {
            for (int k = 1; k <= 2; k++) {
                int nx = x + dx * k, ny = y + dy * k;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (S[nx][ny] != '#') continue;
                if (dp[nx][ny] <= v + 1) continue;
                dp[nx][ny] = v + 1;
                q2.push({nx, ny, v + 1});
                q.push({nx, ny});

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (auto [dx, dy] : dir) {
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if (S[nx][ny] == '#') continue;
                        if (dp[nx][ny] <= v + 1) continue;
                        dp[nx][ny] = v + 1;
                        q2.push({nx, ny, v + 1});
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << dp[c][d] << endl;

    // loop (h, i) {
    //     loop (w, j) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
}