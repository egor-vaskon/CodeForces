#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    map<int, int> cnt;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }

    vector<pair<int, int>> bad_pairs(m);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        if (x > y)
            swap(x, y);

        bad_pairs.emplace_back(x, y);
    }

    sort(bad_pairs.begin(), bad_pairs.end());

    map<int, vector<int>> cnt_r;

    for (auto [x, cnt_x] : cnt)
        cnt_r[cnt_x].emplace_back(x);

    ll best = 0;

    for (auto [x, cnt_x] : cnt) {
        for (const auto& entry : cnt_r) {
            int cnt_y = entry.first;
            const auto& y_s = entry.second;

            if (cnt_y > cnt_x)
                break;

            for (int j = int(y_s.size())-1; j >= 0; --j) {
                int y = y_s[j];
                int u = min(x, y), v = x+y-u;

                if (u != v && !binary_search(bad_pairs.begin(), bad_pairs.end(), make_pair(u, v))) {
                    best = max(best, ll(x + y) * ll(cnt_x + cnt_y));
                    break;
                }
            }
        }
    }

    cout << best << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
